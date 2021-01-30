#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0)
#define int long long
const int N = 2007;
int ar[N+5];
bool pos[N+5];
map<int, int>mp;
vector<pair<int, int> >v;

/**
Idea: After sorting the array in decreasing order
then if we look carefully then we will get the idea.

we must take first number because this number is bigger than any.
if add this number with any number then it will be the large number
    of maximum thats why we must take it.
    then from the rest of the array we can skip only one element if we take from the 1st to last order.
    this skipping element will be added to the 1st element of the array.

Count the frequency of every element so that you can easily find the needed element exist or not.
Every time pick a element and subtract from the maximum and check its exist or not.
Note: if you follow this idea array must be sorted in decreasing order. And always go through left to right.
**/

void solve(int n) {
    int ans = ar[1], mx = ar[1];
    int pos = 0;
    for(int i = 2; i <= n; i++) {
        mp.clear();
        v.clear();
        mx = ar[1];
        for(int j = 2; j<= n; j++) {
            ++mp[ar[j]]; // count the frequency
        }
        --mp[ar[i]];
        bool f = true;
        for(int j = 2; j <= n; j++) {
            if(j==i || mp[ar[j]] == 0) // already assumed i element will be skipped because we do not know which element should we skip.
                continue;
            --mp[ar[j]];
            int r = mx-ar[j];
            if(mp[r]>=1) { // to check this element exist or not
                --mp[r];
                mx = ar[j];
                v.push_back({ar[j], r}); // store every valid pair for printing
            }
            else{
                f = false;
                break;
            }
        }
        if(f){
            pos = i;
            ans += ar[i];
            break;
        }
    }
    if(pos == 0){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << ans << "\n";
    cout << ar[1] << " "<<ar[pos]<<"\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " "<<v[i].second << "\n";
    }
}

int32_t main() {
    faster;
    int ts;
    cin >> ts;
    while(ts--) {
        int n;
        cin >> n;
        n *= 2;
        for(int i = 1; i <= n; i++) {
            cin >> ar[i];
        }
        if(n == 1) {
            cout << "YES\n";
            cout << ar[1] + ar[2] <<"\n";
            cout << ar[1] <<" "<<ar[2]<<"\n";
            continue;
        }
        sort(ar+1, ar+n+1, greater<int>());
        solve(n);
    }
    return 0;
}
