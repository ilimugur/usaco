/*
PROB:zerosum
ID:ilimugu1
LANG:C++11
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector<string> res;
int n;

int getVal(string s)
{
    int n = s.size();
    int sum=0, exp=0;
    bool expPos = true;
    for(int i=0; i < n; ++i)
    {
        if(s[i]== '+')
        {
            sum += (expPos ? exp : -exp);
            exp=0;
            expPos = true;
        }
        else if (s[i] == '-')
        {
            sum += (expPos ? exp : -exp);
            exp=0;
            expPos = false;
        }
        else if(s[i] != ' ')
        {
            exp = exp * 10 + (s[i] - '0');
        }
    }
    sum += (expPos ? exp : -exp);
    return sum;
}

void f(string sum, int t)
{
    if(t > n)
    {
        int val = getVal(sum);
        if(!val)
            res.push_back(sum);
        return;
    }
    string s = sum + "+";
    s.push_back(t + '0');
    f(s, t+1);
    s[s.size() - 2] = '-';
    f(s, t+1);
    s[s.size() - 2] = ' ';
    f(s, t+1);
    
}

int main()
{
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);

    cin >> n;

    f("1", 2);

    sort(res.begin(), res.end());
    for(int i=0; i < res.size(); ++i)
    {
        cout << res[i] << endl;
    }

    return 0;
}
