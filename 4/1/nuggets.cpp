/*
ID:ilimugu1
LANG:C++
PROB:nuggets
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define SIEVELENGTH 65537

using namespace std;

int gcd(int a, int b)
{
    return (b > 0 ? gcd(b, a%b) : a);
}

int solve(const vector<int>& nums)
{
    int n = nums.size();
    bool found = false;
    for(int i=0; i < n; ++i)
    {
        if(nums[i] == 1)
            return 0;
        for(int j=0; j < n; ++j)
        {
            if(i != j)
            {
                if(gcd(nums[i], nums[j]) == 1)
                {
                    found = true;
                    break;
                }
            }
        }
        if(found)
            break;
    }

    int result;
    if(found)
    {
        bool sieve[SIEVELENGTH];
        memset(sieve, false, SIEVELENGTH * sizeof(bool));
        sieve[0] = true;
        for(int i=0; i < SIEVELENGTH; ++i)
        {
            if(sieve[i])
            {
                for(int j=0; j < n; ++j)
                {
                    if(i + nums[j] < SIEVELENGTH)
                        sieve[i + nums[j]] = true;
                }
            }
        }

        for(int i= SIEVELENGTH - 1; i >= 0; --i)
        {
            if(!sieve[i])
            {
                return i;
            }
        }
    }

    return 0;
}

int main()
{
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i < n; ++i)
        cin >> nums[i];
    cout << solve(nums) << endl;

    return 0;
}
