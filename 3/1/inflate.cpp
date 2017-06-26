/*
ID:ilimugu1
PROB:inflate
LANG:C++11
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#define INFDIST 1000000000000000000LL
#define NLIMIT 10000

using namespace std;

int n, m;
pair<int, int> category[NLIMIT];
int dp[10001];

int main()
{
    int i, j, pts = 0;
    
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);

    scanf("%d%d", &m, &n);
    
    for(i=0; i < n; ++i)
    {
        scanf("%d%d", &category[i].first, &category[i].second);
    }

    for(int i=0; i <= m; ++i)
    {
        for(int j=0; j < n; ++j)
        {
            if(i + category[j].second <= m)
            {
                dp[i+category[j].second] = max(dp[i + category[j].second],
                                               dp[i] + category[j].first);
            }
        }
    }

    printf("%d\n", dp[m]);

    return 0;
}
