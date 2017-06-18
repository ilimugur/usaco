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
pair<double, int> order[NLIMIT];
pair<int, int> category[NLIMIT];

int main()
{
    int i, j, pts = 0;
    
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);

    scanf("%d%d", &m, &n);
    
    for(i=0; i < n; ++i)
    {
        scanf("%d%d", &category[i].first, &category[i].second);
        order[i].first = category[i].first / (double) category[i].second;
        order[i].second = i;
    }
    sort(order, order + n);


    i = n-1;
    while(m > 0)
    {
        while( i >= 0 && category[ order[i].second ].second > m )
        {
            --i;
        }
        
        if(i == -1)
        {
            break;
        }
        
        j = m / category[ order[i].second ].second;
        pts += j * category[ order[i].second ].first;
        m -= j * category[ order[i].second ].second;
    }

    printf("%d\n", pts);

    return 0;
}