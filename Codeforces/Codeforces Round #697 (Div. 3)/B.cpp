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
        int n;
        cin >> n;
        if(n < 2020){
            cout << "NO\n";
            continue;
        }
        int md = n%2020;
        int c = n/2020;
        if(md == 0 || md <= c){
            cout << "YES\n";
        }
        else cout <<"NO\n";
    }
    return 0;
}

