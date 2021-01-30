#include<iostream>
#include<list>
#include<queue>
#include<cstdio>
using namespace std;
#define pb push_back
#define inf 2147483647//(2^31 -1)

list<int>adj[200]; // declare as a global

int graph();

void BFS(int s, int v)
{
    int color[200];
    int prev[200];
    int dist[200];
    int i;
    bool flag = false;

    for(i = 1; i <= v; i++)
    {
        color[i] = 0; // color 0 for W, 1 for G and 2 for B
        prev[i] = -1; // -1 means no precious value
        dist[i] = inf; // as far as possible large value
    }
    list<int>::iterator it;
    queue<int>q;
    color[s] = 1; // source as a gray
    dist[s] = 0; // source distance always will be 0
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            if(color[*it]==0)
            {
                dist[*it] = 1 - dist[u];
                prev[*it] = u;
                color[*it] = 1;
                q.push(*it);
            }
           else if(dist[*it]==dist[u])
            {
            	flag = true;
                printf("Not Bipartite\n");
                return;
            }
        }
        color[u] = 2; // when out of queue then color will be Black
    }
   if(!flag)
	{
		printf("Bipartite\n");
	}
}
int main()
{
    int v = graph(); // calling adjacent list as a Graph representation
    printf("Enter source node : ");
    int s;
    scanf("%d",&s);
    if(s<=v && s>0)
        BFS(s,v);
    else
        printf("Invalid\n"); // when out of vertex

    return 0;
}

int graph()
{
    int v, i = 1, x, y;
    printf("Number of vertex : ");
    scanf("%d",&v);
    do
    {
        printf("Edge %d : ",i);
        scanf("%d %d",&x, &y);
        if(x>v || y>v || x<0 || y<0)
            printf("Invalid Input\n");
        else
        {
            adj[x].pb(y);
            adj[y].pb(x);
            i++;
        }
    }
    while(x!= 0 || y!= 0);
    return v;
}
