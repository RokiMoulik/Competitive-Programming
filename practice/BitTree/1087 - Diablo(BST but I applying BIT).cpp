#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sc(n) scanf("%lld",&n)
#define case_print(n) printf("Case %lld:\n", ++n)
#define print(n) printf("%lld\n",n)
const int N = 150007;
int tree[N], a[N], n;

int query(int i) {
    int sum = 0;
    while(i>0) {
        sum += tree[i];
        i -= (i&(-i));
    }
    return sum;
}

void update(int i, int val) {
    while(i < N) {
        tree[i] += val;
        i += (i&(-i));
    }
}
int32_t main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t, cs = 0;
    sc(t);
    while(t--) {
        case_print(cs);

        int r, x, y, q;
        char ch;
        sc(n), sc(q);
        for(int i = 1; i <= n; i++) {
            sc(a[i]);
        }
        for(int i = 1; i <= n; i++) {
            update(i, 1);
        }
        while(q--) {
            getchar();
            scanf("%c",&ch);
            getchar();

            if(ch=='a') {
                sc(r);
                a[++n] = r;
                update(n, 1);
            } else {
                sc(x);
                int l = 1, r = n;
                bool f = 0;
                while(l<=r) {
                    int mid = (l+r)/2;
                    int res = query(mid);

                    if(res < x) {
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }

                }
                if(query(l) != x){
                    printf("none\n");
                }
                else{
                    print(a[l]);
                    update(l, -1);
                }
            }
        }
        memset(tree, 0, sizeof(tree));

    }
    return 0;

}
