/*
ID:ilimugu1
LANG:C++
PROB:ditch
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MLIMIT 200
#define INFINITY 2000000001
using namespace std;

int m, n;
int adjMatrix[MLIMIT][MLIMIT];

int dijkstra(int src, int dest, vector<int>& path)
{
    priority_queue< pair<int, int> > pq;
    int parent[MLIMIT];
    int flow[MLIMIT];

    for(int i=0; i < m; ++i)
    {
        flow[i] = 0;
        parent[i] = -1;
    }

    pq.push(make_pair(INFINITY, src));
    flow[src] = INFINITY;
    while(!pq.empty())
    {
        pair<int, int> top = pq.top();
        int flowAmount = top.first;
        int u = top.second;
        pq.pop();

        if(flow[u] > flowAmount)
            continue;

        if(u == dest)
            break;

        for(int v=0; v < m; ++v)
        {
            if(adjMatrix[u][v] > 0 && flow[v] < min(flowAmount, adjMatrix[u][v]))
            {
                flow[v] = min(flowAmount, adjMatrix[u][v]);
                parent[v] = u;
                pq.push( make_pair(flow[v], v) );
            }
        }
    }

    int tmp = dest;
    while(tmp != src)
    {
        path.push_back( tmp );
        tmp = parent[tmp];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());

    return flow[dest];
}

unsigned long long maxFlow(int source, int sink)
{
    unsigned long long res = 0LL;

    while(true)
    {
        vector<int> path;
        int flow = dijkstra(source, sink, path);

        if(flow == 0)
            break;

        res += (unsigned long long) flow;

        for(int i=1; i < path.size(); ++i)
        {
            int u = path[i-1], v = path[i];

            adjMatrix[u][v] -= flow;
            adjMatrix[v][u] += flow;
        }
    }

    return res;
}

int main()
{
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);

    cin >> n >> m;

    for(int i=0; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u - 1][v - 1] += w;
    }

    cout << maxFlow(0, m-1) << endl;

    return 0;
}
