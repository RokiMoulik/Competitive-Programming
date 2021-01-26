#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(0)

const int N = 0;
int ar[N+5];

int32_t main()
{
    faster;
    int ts;
    cin >> ts;
    while(ts--){
        int n, m, c = 0;
        cin >> n;
        if(n&1){
            cout << "YES\n";
        }
        else{
            while(n > 1 && (n%2) == 0){
                n /= 2;
            }
            if(n == 1){
                cout << "NO\n";
            }
            else cout << "YES\n";
        }
    }
    return 0;
}
