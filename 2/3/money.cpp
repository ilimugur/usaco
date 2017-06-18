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

long long dp[10001];

int main()
{
    int n, v;
    long long vals[25];

//    freopen("money.in", "r", stdin);
//    freopen("money.out", "w", stdout);

    cin >> v >> n;
    for(int i=0; i < v; ++i)
    {
        cin >> vals[i];
    }
    sort(vals, vals + v);

    dp[0] = 1;
    for(int i=1; i <= n; ++i)
    {
        for(int j=0; j < v && i >= vals[j]; ++j)
        {
            dp[i] += dp[ i - vals[j] ];
        }
        cout << dp[i] << endl;
    }

    cout << dp[n] << endl;

    return 0;
}
