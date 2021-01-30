#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sc(a) scanf("%lld", &a)
const int M = 1e9+7;
vector<pair<int, int> >v;
int n, tree[100005];
int query(int r){
    int sum = 0;
    while(r > 0){
        sum = (sum + tree[r]) % M;
        r -= (r & (-r));
    }
    return sum;
}

void update(int r, int val){
    while(r<=n){
        tree[r] = (tree[r] + val) % M;
        r += (r & (-r));
    }
}

int32_t main(){
    int t, cs = 0;
    sc(t);
    while(t--){
        int x, k, r, sum = 0, ans = 0;
       // cout <<t << endl;
        sc(n);
        for(int i = 1; i <= n; i++){
            sc(x);
            v.push_back(make_pair(x, i));
        }
        sort(v.begin(), v.end());
        int preItem = -1;
        int preSum = 0;

        for(int i = 0; i < v.size(); i++){
            int fs = v[i].first;
            int snd = v[i].second;

            sum = (1 + query(snd-1) ) % M;

            if(fs==preItem){
                sum -= preSum;
                sum %= M;
                preSum = (preSum%M + sum%M)%M;
            }
            else{
                 preSum = sum;
            }
            ans = (ans%M + sum%M) %M;
            update(snd, sum);
            preItem = fs;

            //cout << sum << " "<<snd<<" "<<endl;
        }

        printf("Case %lld: %lld\n", ++cs, ans);
        memset(tree, 0, sizeof(tree));
        v.clear();
    }
    return 0;
}
