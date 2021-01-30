#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(0)
const int N = 2e5+5;
pair<int, int>p[N+5];
int boy[N+5], girl[N+5];

void solve(int a, int b, int k) {
    for(int i = 0; i <= a; i++)
        boy[i] = 0;
    for(int i = 0; i <= b; i++)
        girl[i] = 0;
    for(int i = 1; i <= k; i++) {
        boy[p[i].first]++;
        girl[p[i].second]++;
    }
    int ans = 0;
    for(int i = 1; i <= k; i++) {
        ans += (k-boy[p[i].first] - girl[p[i].second] + 1);
    }
    cout << ans/2 << "\n";
}

int32_t main() {
    faster;
    int ts;
    cin >> ts;
    while(ts--) {
        int a, b, k;
        cin >> a >> b >> k;
        for(int i = 1; i <= k; i++) {
            cin >> p[i].first;
        }
        for(int i = 1; i <= k; i++) {
            cin >> p[i].second;
        }
        solve(a, b, k);
    }
    return 0;
}

