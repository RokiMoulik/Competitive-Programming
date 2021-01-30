#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(0)
const int N = 1e5+7;
int ar[N+5];
int br[N+5];
int cr[N+5];
pair<int, int>p[N+5];
int ans[N+5];

void solve(int n){
    int mx = 0, cur = 0;
    for(int i = 2; i <= n; i++){
        cur = abs(ar[i] - br[i]);
        cur += cr[i] + 1;
        ans[i] = cur;
        if(abs(ar[i]- br[i]) == 0) continue;
        int d = ans[i-1] + cur;
        d -= (2*abs(ar[i] - br[i]));
        ans[i] = max(cur, d);

    }
    for(int i = 2; i <= n; i++){
        mx = max(mx, ans[i]);
    }
    cout << mx << "\n";
}

int32_t main()
{
    faster;
    int ts;
    cin >> ts;
    while(ts--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> cr[i];
            ans[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            cin >> ar[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> br[i];
        }
        solve(n);
    }
    return 0;
}

