/*
ID:ilimugu1
PROB:agrinet
LANG:C++11
*/
#include <cstdio>
#define INFDIST 1000000000000000000LL
#define NLIMIT 100

using namespace std;

long long adjMatrix[NLIMIT][NLIMIT];
int n;

long long prims()
{
	long long totalCost = 0LL;
	bool covered[NLIMIT];
	long long distance[NLIMIT];
//	int parent[NLIMIT];
	int numCovered = 1;
	int i, u;

	for(i=1; i < n; ++i)
	{
		covered[i] = false;
		distance[i] = INFDIST;
//		parent[i] = -1;
	}

	covered[0] = true;
	distance[0] = 0;
//	parent[0] = -1;
	for(i=1; i < n; ++i)
	{
		distance[ i ] = adjMatrix[0][i];
//		parent[ i ] = 0;
	}
	
	while(numCovered < n)
	{
		u = -1;
		for(i=0; i < n; ++i)
			if(!covered[i] && (u == -1 || distance[ i ] < distance[u]))
			{
				u = i;
			}

		covered[u] = true;
		totalCost += distance[u];
		numCovered++;
		

		for(i=0; i < n; ++i)
		{
			if(i != u && !covered[ i ] && distance[ i ] > adjMatrix[u][i])
			{
				distance[ i ] = adjMatrix[u][i];
//				parent[ i ] = u;
			}
		}
	}

	return totalCost;
}

int main()
{
	int i, j;
	
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);

	scanf("%d", &n);

	for(i=0; i < n; ++i)
	{
		for(j=0; j < n; ++j)
		{
			scanf("%lld", adjMatrix[i] + j);
		}
	}

	printf("%lld\n", prims());

	return 0;
}