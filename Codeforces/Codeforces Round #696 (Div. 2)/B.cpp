#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios::sync_with_stdio(0)

bool is_prime(int p){
    if(p == 2 || p == 3) return false;
    for(int i = 2; i*i <= p; i++){
        if(p%i == 0) return true;
    }
    return false;
}

int32_t main() {
    faster;
    int ts;
    cin >> ts;
    while(ts--){
        int d;
        int a = 0, b = 0;
        cin >> d;
        a = d+1;

        while(is_prime(a)){
            a++;
        }
        b = a+d;
        while(is_prime(b)){
            b++;
        }
//        cout << a <<" "<<b<<endl;
        cout << a*b << "\n";
    }

    return 0;
}

