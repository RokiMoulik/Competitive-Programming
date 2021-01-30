#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(0)
const int N = 2e5+5;
int ar[N+5];
int pre[N+5];
int suf[N+5];

bool check(int n, int a[]) {
    int premn = 0;
    for(int i = 1; i <= n; i++) {
        if(premn <= a[i]){
            premn = a[i]-premn;
        }
        else{
            return false;
        }
    }
    return (premn == 0) ? true : false;
}

void solve(int n) {
    if(check(n, ar)){
        cout << "YES\n";
        return;
    }
    swap(ar[1], ar[2]);
    if(check(n, ar)){
        cout << "YES\n";
        return;
    }
    swap(ar[1], ar[2]);
    swap(ar[n-1], ar[n]);
    if(check(n, ar)){
        cout << "YES\n";
        return;
    }
    swap(ar[n-1], ar[n]);

    pre[1] = ar[1];
    for(int i = 2; i <= n; i++) {
        if(pre[i-1] == -1) {
            pre[i] = -1;
        } else if(pre[i-1] <= ar[i]) {
            pre[i] = ar[i]-pre[i-1];
        } else {
            pre[i] = -1;
        }
    }

    suf[n] = ar[n];
    for(int i = n-1; i >= 1; i--) {
        if(suf[i+1] == -1) {
            suf[i] = -1;
        } else if(ar[i] >= suf[i+1]) {
            suf[i] = ar[i] - suf[i+1];
        } else {
            suf[i] = -1;
        }
    }

    for(int i = 2; i+2<= n; i++) {
        int tmp[] = {0, pre[i-1], ar[i+1], ar[i], suf[i+2]};
        if(pre[i-1] == -1 || suf[i+2] == -1) {
            continue;
        }
        if(check(4, tmp)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    faster;
    int ts;
    cin >> ts;
    while(ts--) {
        int n;
        cin >> n;
        int sum = 0, mx = 0;
        for(int i = 1; i <= n; i++) {
            cin >> ar[i];
            sum += ar[i];
        }
        if(sum&1 || n == 1) {
            cout << "NO\n";
            continue;
        }
        solve(n);

    }

    return 0;
}


/*
1
4
5 9 6 8

*/
