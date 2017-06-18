/*
ID:ilimugu1
LANG:C++
PROB:fence6
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <set>
#include <climits>
#define NLIMIT 201

using namespace std;

int visited[NLIMIT];
int shortestPerimeter;
vector<int> endpoints[NLIMIT][2];
int lengths[NLIMIT];
int N;

void computeShortestPasturePerimeter(int index, int destinationListIndex, int perimeter)
{
    visited[index] = 1;
    perimeter += lengths[index];

    // Find out which children's list DFS should search
    for(int i=0; i < endpoints[index][destinationListIndex].size(); ++i)
    {
        int childIndex = endpoints[index][destinationListIndex][i];
        switch(visited[childIndex])
        {
            case 0:
            {
                int childDestinationListIndex = 0;
                for(int i=0; i < endpoints[childIndex][0].size(); ++i)
                {
                    if(endpoints[childIndex][0][i] == index)
                    {
                        childDestinationListIndex = 1;
                        break;
                    }
                }
                computeShortestPasturePerimeter(childIndex, childDestinationListIndex, perimeter);
                break;
            }
            case 1:
            {
                if(perimeter < shortestPerimeter)
                {
                    shortestPerimeter = perimeter;
                }
                break;
            }
            default:
                break;
        }
    }

    visited[index] = 0;
}

int main()
{
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);

    cin >> N;
    for(int i=1; i <= N; ++i)
    {
        int index, endpointIntersections[2];
        cin >> index;
        cin >> lengths[index] >> endpointIntersections[0] >>
                                 endpointIntersections[1];
        for(int j=0; j < 2; ++j)
        {
            for(int k=0; k < endpointIntersections[j]; ++k)
            {
                int tmp;
                cin >> tmp;
                endpoints[index][j].push_back(tmp);
            }
        }
    }


    shortestPerimeter = INT_MAX;
    for(int i=1; i <= N; ++i)
    {
        if(endpoints[i][0].size() > 0)
        {
            memset(visited, 0, sizeof(int) * (N+1));
            computeShortestPasturePerimeter(i, 0, 0);
        }

        if(endpoints[i][1].size() > 0)
        {
            memset(visited, 0, sizeof(int) * (N+1));
            computeShortestPasturePerimeter(i, 1, 0);
        }
    }

    cout << shortestPerimeter << endl;

    return 0;
}
