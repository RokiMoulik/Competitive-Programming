#include<bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
#define pb push_back
typedef pair<int, int> ipair;
class Graph
{
    int v; //no. of vertices
    list<pair<int, int> >*adj;
public:
    Graph(int v);
    void addEdge(int u, int v, int w);
    void shortest_path(int s); // for printing
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<ipair>[v];
}
void Graph::addEdge(int u, int v, int w)
{
    adj[u].pb(make_pair(v,w));
    adj[v].pb(make_pair(u,w));
}
void Graph::shortest_path(int src)
{
    priority_queue<ipair,vector<ipair>,greater<ipair> >pq;
    vector<int>dist(v,INF);
    pq.push(make_pair(0,src)); //edited
    dist[src] = 0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        list<pair<int , int> >::iterator i;
        for(i = adj[u].begin(); i!=adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if(dist[v]>dist[u]+weight)
            {
                dist[v] = dist[u]+weight;
                pq.push(make_pair(dist[v], v));
            }
        }

    }
// ja kam ace eihane koro
    printf("vertex distance from source\n");
    for(int i = 1; i < v; i++){
        printf("%d \t %d\n",i,dist[i]);
    }
}

int main()
{
    int v, e;
    cout<<"Enter vertex : "; cin>>v;
    Graph g(v+1);
    cout<<"Enter Edge: "; cin>>e;
    int u, vv, w, i;
    for( i = 0; i < e; i++)
    {
        cin>>u>>vv>>w;
        g.addEdge(u,vv,w);
    }
    g.shortest_path(1);
    return 0;
}
