/*
ID:ilimugu1
PROB:humble
LANG:C++11
*/
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> q;
int main()
{
    int n, k;
    long long limit = INT_MAX;
    vector<long long> factor;

	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	
    scanf("%d%d", &k, &n);
    factor.resize(k);
    for(int i = 0; i < k; ++i)
	{
        scanf("%lld", &factor[i]);
		q.push(-factor[i]);
	}

	int front;
    for(int i=0; i < n; ++i)
    {
		front = -q.top();
		q.pop();
		for(int j=0; j < k; ++j)
		{
			if(INT_MAX >= front * factor[j])
			{
				q.push(front * -factor[j]);
				if(front % factor[j] == 0)
				{
					// This if and reverse iteration prevents duplicates in queue.
					break;
				}
			}
		}
    }
    
    printf("%d\n", front);
    
    return 0;
}