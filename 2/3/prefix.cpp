/*
PROB:prefix
ID:ilimugu1
LANG:C++11
*/

#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

char str[200001];
bool dp[200001];
set<string> p;
string s, prefix, tmpPrefix;
int main()
{
    int n = 0, LP = 0, maxPrefixLen = 0;

    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    scanf("%s", str);
    while(str[0] != '.')
    {
        prefix = str;
        p.insert(prefix);
        maxPrefixLen = max(maxPrefixLen, (int)prefix.size());
        scanf("%s", str);
    }

    
    while(scanf("%s", str) == 1)
    {
        s.append(str);
    }
    n = s.size();

    for(int j=1; j <= maxPrefixLen; ++j)    // O(P)
    {
        string t = s.substr(0, j);    // O(P)
        if(p.find(t) != p.end())    //O(logM)
        {
            dp[j] = true;
            if(j > LP)
                LP = j;
        }
    }
    if(LP > 0)
    {
        for(int i=1; i <= LP; ++i)   // O(N)
        {
            if(!dp[i])
                continue;
            string t = "";
            for(int j=1; j <= maxPrefixLen; ++j)    // O(P)
            {
                t.push_back(s[i+j-1]);
                if(t.size() == j && p.find(t) != p.end())    //O(logM)
                {
                    dp[i+j] = true;
                    if(i+j > LP)
                        LP = i+j;
                }
            }
        }
    }
    printf("%d\n", LP);


    return 0;
}
