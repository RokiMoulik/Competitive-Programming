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
        int n, k;
        cin >> n >> k;
        if(n%k == 0){
            cout << 1 << "\n";
        }
        else if(n < k){
            int ans = (k+n-1)/n;
            cout << ans << "\n";
        }
        else{
            cout << 2 <<"\n";
        }
    }
    return 0;
}
