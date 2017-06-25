/*
PROB:money
ID:ilimugu1
LANG:C++11
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#define MODULUS 9901

using namespace std;

pair<long long, long long> dp[10001];

int main()
{
    int n, v;
    long long vals[25];

    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);

    cin >> v >> n;
    for(int i=0; i < v; ++i)
    {
        cin >> vals[i];
    }
    sort(vals, vals + v);

    dp[0].first = 1;
    dp[0].second = 0;
    for(int j=0; j < v; ++j)
    {
        for(int i=0; i <= n && i + vals[j] <= n; ++i)
        {
            dp[i + vals[j]].first += dp[i].first;
        }
    }

    cout << dp[n].first << endl;

    return 0;
}
