/*
ID:ilimugu1
PROB:fracdec
LANG:C++11
 */
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map< long long, int > visited;

int main()
{
    long long resBeforeDot;
    long long n, d;
    long long rem, divisor;

    int loopStart = 0;
    string soFar, res;

    char newDigit;
    bool found = false;
    
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    scanf("%lld%lld", &n, &d);

    resBeforeDot = n / d;
    res = "";
    while(resBeforeDot)
    {
        newDigit = '0' + (char)(resBeforeDot % 10);
        res.push_back(newDigit);
        resBeforeDot /= 10;
    }
    reverse(res.begin(), res.end());
    if(!res.size())
        res.push_back('0');
    res.push_back('.');

    n %= d;

    rem = n;
    divisor = d;
    soFar = "";

    while(!found)
    {
        if(!rem)
        {
            if(!soFar.size())
                soFar.push_back('0');
            break;
        }

        bool got10 = false;
        while(rem < divisor)
        {
            rem *= 10;
            if(got10)
            {
                soFar.push_back('0');
            }
            got10 = true;
        }
        map< long long, int>::iterator it = visited.find(rem);
        if(it!= visited.end())
        {
            loopStart = it->second;
            found = true;
        }
        else
        {
            visited.insert( make_pair( rem, soFar.size() ) );
            newDigit = '0' + (char)(rem / divisor);
            soFar.push_back(newDigit);
            rem %= divisor;
        }
    }

    if(found)
    {
        string beforeLoop = "", loop;
        if(loopStart > 0)
        {
            for(int i=0; i < loopStart; ++i)
            {
                beforeLoop = soFar.substr(i, loopStart - i);
                string suffix = soFar.substr(soFar.size() - beforeLoop.size());
        
                if(beforeLoop.size() > 0 && suffix == beforeLoop)
                {
                    soFar = soFar.substr(0, soFar.size() - suffix.size());
                    loopStart = i;
                    break;
                }
            }
        }

        beforeLoop = soFar.substr(0, loopStart);
        loop = soFar.substr(loopStart);

        res += beforeLoop + "(" + loop + ")";
    }
    else
        res += soFar;

    int i, lineNum = 1;
    for(i=0; i < res.size(); ++i)
    {
        if(lineNum * 76 == i)
        {
            printf("\n");
            lineNum++;
            --i;
        }
        else
        {
            printf("%c", res[i]);
        }
    }
    printf("\n");

    return 0;
}
