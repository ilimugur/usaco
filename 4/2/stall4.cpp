/*
ID:ilimugu1
LANG:C++
PROB:stall4
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

int bfs(vector< vector< pair<int, int> > >& adjList, int src, int sink,
        vector<int>& path)
{
    queue< pair<int, int> > q;
    vector<int> parent(adjList.size(), -1);
    q.push(make_pair(src, INF));

    int res = 0;
    while(!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();

        if(front.first == sink)
        {
            res = front.second;
            break;
        }

        for(int i=0; i < adjList[front.first].size(); ++i)
        {
            int v = adjList[front.first][i].first, w = adjList[front.first][i].second;
            if(parent[v] == -1 && v != src)
            {
                parent[v] = front.first;
                q.push(make_pair(v, min(front.second, w)));
            }
        }
    }

    if(res > 0)
    {
        int tmp = sink;
        path.clear();
        while(tmp != -1)
        {
            path.push_back(tmp);
            tmp = parent[tmp];
        }
        reverse(path.begin(), path.end());
    }

    return res;
}

int maxFlow(vector< vector< pair<int, int> > >& adjList, int src, int sink)
{
    int flow = 0, totalFlow = 0;
    do
    {
        vector<int> path;
        flow = bfs(adjList, src, sink, path);

        if(flow == 0)
            break;

        totalFlow += flow;

        for(int i=1; i < path.size(); ++i)
        {
            int u =  path[i-1], v =  path[i], w;
            for(int j=0; j < adjList[u].size(); ++j)
            {
                if(adjList[u][j].first == v)
                {
                    w = adjList[u][j].second;
                    swap(adjList[u][j], adjList[u].back());
                    adjList[u].pop_back();
                    break;
                }
            }
            adjList[v].push_back(make_pair(u, w));
        }
    }
    while(flow > 0);

    return totalFlow;
}

int solve(int m, vector< vector<int> >& cowPreferences)
{
    int res = 0;
    int n = cowPreferences.size();
    int src = 0, sink = m + n + 1;
    vector< vector< pair<int, int> > > adjList(sink + 1);

    for(int i=1; i <= n; ++i)
        adjList[src].push_back( make_pair(i, 1));

    for(int i=n+1; i < sink; ++i)
        adjList[i].push_back( make_pair(sink, 1));

    for(int i=0; i < n; ++i)
        for(int cow=i+1, j=0; j < cowPreferences[i].size(); ++j)
            adjList[cow].push_back( make_pair(n + cowPreferences[i][j] , 1));

    res = maxFlow(adjList, src, sink);

    return res;
}

int main()
{
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector< vector<int> > cowPreferences(n);

    for(int i=0; i < n; ++i)
    {
        int k;
        cin >> k;
        cowPreferences[i].resize(k);
        for(int j=0; j < k; ++j)
        {
            cin >> cowPreferences[i][j];
        }
    }

    cout << solve(m, cowPreferences) << endl;

    return 0;
}
