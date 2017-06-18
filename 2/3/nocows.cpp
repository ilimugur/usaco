/*
PROB:nocows
ID:ilimugu1
LANG:C++11
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#define MODULUS 9901

using namespace std;

int dp[201][101];

int main()
{
    int n, k;

    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);

    cin >> n >> k;
    dp[1][1] = 1;

    for(int i=1; i <= n; i+=2)
    {
        int bound = min((i+1)/2, k);
        for(int j=1; j <= bound; ++j)
        {
            for(int t = 1; t < i; t += 2)
            {
                int otherSubtreeNodes = i - 1 - t;
                for(int z = 1; z < j; ++z)
                {
                    if(z < j-1 || t <= otherSubtreeNodes)
                    {
                        int tmp = dp[t][j-1] * dp[otherSubtreeNodes][z] % MODULUS;
                        if(!(t == otherSubtreeNodes && j-1 == z))
                        {
                            tmp = 2 * tmp % MODULUS;
                        }
                        dp[i][j] = (dp[i][j] + tmp) % MODULUS;
                    }
                }
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
