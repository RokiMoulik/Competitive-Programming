#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+7;
int n, tree[N];

void update_from_here(int indx, int val) {
    int sum = 0;
    while(indx <=n) {
        tree[indx] += val;
        indx += (indx & (-indx));
        //for next index :
        //2's complement
        //AND with original number
        //Add to the original number
    }
}

void update(int l, int r, int val) {
    update_from_here(l, val);
    //cout <<"roki"<<endl;
    update_from_here(r+1, val*(-1));
}

int query(int indx) {
    int sum = 0;
    while(indx >=1) {
        sum += tree[indx];
        indx -= (indx & (-indx));
        //for Parent index :
        //2's complement
        //AND with original number
        //Subtract to the original number

    }
    return sum;
}

int32_t main() {
    int t, cs = 0;
    scanf("%d", &t);
    while(t--) {
       // cout <<t << endl;
        memset(tree, 0, sizeof(tree));
        int u, val, a, b;
        scanf("%d%d", &n, &u);
       // cout << n << " "<<u << endl;

        while(u--) {
            scanf("%d%d%d", &a, &b, &val);
            update(a+1, b+1, val);
        }
        int m, q;
        scanf("%d", &m);
        while(m--){
            int q;
            scanf("%d", &q);
            printf("%d\n", query(q+1));
        }
    }
    return 0;
}


