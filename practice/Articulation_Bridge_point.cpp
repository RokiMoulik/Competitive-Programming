#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 100
#define inf INT_MAX
int color[N+5], t, prv[N+5], f[N+5], low[N+5], d[N+5];
vector<int>g[N+5];
int n;


void dfs_visit(int v){
    color[v] = 1;
    t = t+1;
    d[v] =  t;
    low[v] = d[v];
    for(int i = 0; i < g[v].size(); i++){
            int w = g[v][i];
            //cout<<w<<endl;
        if(color[w]==0){
            prv[w] = v;
            dfs_visit(w);
            if(low[w]>d[v]){
                cout<<v<<" - "<<w<<" is a bridge"<<endl;
            }
//            if(low[w]>=d[v]){
//                cout<<v<<" is an articulation point!"<<endl;
//            }
            if(low[w]<low[v])
                low[v] = low[w];
        }
        else if(prv[v]!=w){
            low[v] = min(d[w], low[v]);
        }
    }

}

void DFS(){
    for(int i = 0; i <=n; i++){
        color[i] = 0;
        prv[i] = -1;
        low[i] = inf;
        f[i] = d[i] = inf;

    }
    t = 0;
    for(int i = 0; i<n; i++){
        if(color[i]==0){
            dfs_visit(i);
        }
    }

}

int main()
{
    freopen("Articulation_Bridge_point.txt","r",stdin);
    cout<<"Enter Node Number: ";
    cin>>n;
    int m;
    cout<<"Enter Edge Number: \n";
    cin>>m;
    int x, y;

    for(int i = 0; i < m; i++){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    DFS();
    return 0;
}
