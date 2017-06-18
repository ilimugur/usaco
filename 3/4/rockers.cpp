/*
ID:ilimugu1
LANG:C++
PROB:rockers
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define NLIMIT 21
#define TLIMIT 21
#define MLIMIT 21
 
using namespace std;
 
int N, T, M;
int songs[20];
 
int solve(int songIndex, int diskIndex, vector<int>& diskUsage)
{
	if (songIndex == N || diskIndex == M)
		return 0;
 
	int result;
	if (diskUsage[diskIndex] + songs[songIndex] <= T)
	{
		diskUsage[diskIndex] += songs[songIndex];
		result = 1 + solve(songIndex+1, diskIndex, diskUsage);
		diskUsage[diskIndex] -= songs[songIndex];
	}
	else 
		result = solve(songIndex, diskIndex+1, diskUsage);

	result = max(result, solve(songIndex+1, diskIndex, diskUsage));

	return result;
}
 
int main()
{
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);
 
	cin >> N >> T >> M;
	for (int i = 0; i < N; ++i)
		cin >> songs[i];
 
	string usage(N, '0');
	vector<int> diskUsage(M, 0);
 
	cout << solve(0, 0, diskUsage) << endl;
 
	return 0;
}
