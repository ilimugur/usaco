/*
ID:ilimugu1
PROB:contact
LANG:C++11
*/
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define VARIETIES 8192
#define KEEPERS 200000
using namespace std;

vector< pair<int, string> > occurances;

bool compareStr(const string &s, const string &z)
{
    if(s.size() < z.size())
        return true;
    else if(s.size() == z.size() && s.compare(z) < 0)
        return true;
    return false;
}

int main()
{
    int a, b, n;
    int tmpScores[VARIETIES];
    string s, line;

    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    cin >> a >> b >> n;
    
    while(1)
    {
        line = "";
        cin >> line;
        if(line.size() > 0)
            s += line;
        else
            break;
    }

    
    for(int i=a; i <= b; ++i)
    {
        int p = 0, r = i-1, q, mask;
        for(int j=0; j < VARIETIES; ++j)
        {
            tmpScores[j] = 0;
        }
        mask = q = 0;
        for(int j=0; j < i; ++j)
        {
            q = (q << 1) | (s[j]=='1' ? 1 : 0);
            mask = (mask << 1) | 1;
        }

        while(r < s.size())
        {
            // Process q
            tmpScores[q]++;

            p++;
            r++;
            q = ((q << 1) | (s[r]=='1' ? 1 : 0)) & mask;
        }

        for(int j=0; j < VARIETIES; ++j)
        {
            if(tmpScores[j] > 0)
            {
                string z;
                for(int k=i-1; k >= 0; --k)
                {
                    z.push_back(((j >> k) & 1 ? '1' : '0'));
                }

                occurances.push_back( make_pair(tmpScores[j], z) );
            }
        }
        sort(occurances.rbegin(), occurances.rend());
        if(occurances.size() > KEEPERS)
            occurances.resize(KEEPERS);
    }

    vector< pair<int, vector<string> > > toPrint(n);
    toPrint[0].first = occurances[0].first;
    toPrint[0].second.push_back(occurances[0].second);
    int i = 1,j=0;

    while(n && i < occurances.size())
    {
        if(occurances[i].first < occurances[i-1].first)
        {
            sort(toPrint[j].second.begin(), toPrint[j].second.end(), compareStr);
            if(--n)
            {
                ++j;
                toPrint[j].first = occurances[i].first;
                toPrint[j].second.push_back(occurances[i].second);
            }
        }
        else
            toPrint[j].second.push_back(occurances[i].second);
        ++i;
    }
    n = j;

    for(i=0, j=1; i <= n; ++i)
    {
        cout << toPrint[i].first << endl;
        cout << toPrint[i].second[0];
        for(j=1; j < toPrint[i].second.size(); ++j)
        {
            if(j % 6 == 0)
            {
                cout << endl;
                cout << toPrint[i].second[j];
            }
            else
                cout << " " << toPrint[i].second[j];
        }
        cout << endl;
    }

    return 0;
}