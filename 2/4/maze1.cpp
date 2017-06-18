/*
ID:ilimugu1
PROB:maze1
LANG:C++11
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int adjMask[100][38];
int visited[2][100][38];
int n, m, w, h;

int dijkstra(int i, int j, int shortestDist[100][38])
{
    priority_queue< pair<int, pair<int, int> > > q;
    q.push( make_pair( 1, make_pair(i, j) ) );

    while(!q.empty())
    {
        pair< int, pair<int, int> > front = q.top();
        q.pop();
        int p = front.second.first, r = front.second.second, depth = front.first;
        if(depth < shortestDist[p][r])
        {
            shortestDist[p][r] = depth;
            if( p > 0 && (adjMask[p][r] & 1) && depth + 1 < shortestDist[p-1][r])
                q.push( make_pair( depth+1, make_pair( p-1, r )));
            if( r < w-1 && (adjMask[p][r] & 2) && depth + 1 < shortestDist[p][r+1])
                q.push( make_pair( depth+1, make_pair( p, r+1 )));
            if( p < h-1 && (adjMask[p][r] & 4) && depth + 1 < shortestDist[p+1][r])
                q.push( make_pair( depth+1, make_pair( p+1, r )));
            if( r > 0 && (adjMask[p][r] & 8) && depth + 1 < shortestDist[p][r-1])
                q.push( make_pair( depth+1, make_pair( p, r-1 )));
        }
    }
}

int main()
{
    int j;
    int entries[2][2], numEntries = 0;
    char buffer[3][256];

    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);

    scanf("%d%d", &w, &h);
    n = 2 * h + 1;
    m = 2 * w + 1;

    // Read input
    getchar();
    for(j=0; scanf("%c", *buffer + j) == 1, buffer[0][j] != '\n'; ++j)
        if(buffer[0][j] == ' ')
        {
            entries[numEntries][0] = 0;
            entries[numEntries++][1] = (j-1)/2;
        }
    buffer[0][j] = '\0';

    for(int i=0; i < h; ++i)
    {
        for(int t=1; t <= 2; ++t)
        {
            for(j=0; scanf("%c", buffer[t] + j) == 1, buffer[t][j] != '\n'; ++j);
            buffer[t][j] = '\0';
        }
        
        for(int k=1; k < m; k+=2)
        {
            int mask = 15;
            if(buffer[0][k] == '-')
                mask &= 14;  // north 1
            if(buffer[1][k+1] == '|')
                mask &= 13;  // east 2
            if(buffer[2][k] == '-')
                mask &= 11;  // south 4
            if(buffer[1][k-1] == '|')
                mask &= 7;   // west 8
            adjMask[i][(k-1)/2] = mask;
        }

        if(buffer[1][0] == ' ')
        {
            entries[numEntries][0] = i;
            entries[numEntries++][1] = 0;
        }
        if(buffer[1][strlen(buffer[1]) - 1] == ' ')
        {
            entries[numEntries][0] = i;
            entries[numEntries++][1] = w-1;
        }

        for(int j=0; buffer[2][j] != '\0'; ++j)
            buffer[0][j] = buffer[2][j];
    }

    
    for(int j=0; buffer[2][j] != '\0'; ++j)
        if(buffer[2][j] == ' ')
        {
            entries[numEntries][0] = h-1;
            entries[numEntries++][1] = (j-1)/2;
        }

    for(int k=0; k < 2; ++k)
        for(int i=0; i < h; ++i)
            for(int j=0; j < w; ++j)
                visited[k][i][j] = 1000000000;

    dijkstra(entries[0][0], entries[0][1], visited[0]);
    dijkstra(entries[1][0], entries[1][1], visited[1]);

    int result = 0;
    for(int i=0; i < h; ++i)
        for(int j=0; j < w; ++j)
        {
            result = max(result, min(visited[0][i][j], visited[1][i][j]));
        }
    cout << result << endl;

    return 0;
}
