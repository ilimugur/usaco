/*
ID:ilimugu1
PROB:concom
LANG:C++11
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 100
#define N_IND 101

using namespace std;

int info[10000];
vector< pair<int, int> > adjList[N_IND];
int visited[N_IND];

void dfs(int u, int shares)
{
    visited[u] = shares;

    for(int i=0; i < adjList[u].size(); ++i)
    {
        int v = adjList[u][i].first, cost = adjList[u][i].second;
        if(visited[v] <= 50 && visited[v] + cost > 50)
        {
            dfs(v, visited[v] + cost);
        }
        else
        {
            visited[v] += cost;
        }
    }
}


int main()
{
    int n, i, j, p;
    int numCom = 0;

    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);

    cin >> n;
    for(int k=0; k < n; ++k)
    {
        cin >> i >> j >> p;
        bool notFound = true;
        for(int t=0; t < adjList[i].size(); ++t)
        {
            if(adjList[i][t].first == j)
            {
                adjList[i][t].second += p;
                notFound = false;
            }
        }
        if(notFound)
            adjList[i].push_back(make_pair(j, p));
    }

    for(int i=1; i <= N; ++i)
    {
        for(int j=1; j <= N; ++j)
        {
            visited[j] = 0;
        }

        dfs(i, 100);

        for(int j=1; j <= N; ++j)
        {
            if(visited[j] > 50 && i != j)
            {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}
