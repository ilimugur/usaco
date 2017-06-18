/*
ID:ilimugu1
PROB:ttwo
LANG:C++11
*/
#include <algorithm>
#include <string>
#include <iostream>
#define SIZE 10
using namespace std;

string grid[SIZE];

void move(int &i, int &j, int &dir)
{
	switch(dir)
	{
		case 0:
			// north
			if(i > 0 && grid[i-1][j] != '*')
				--i;
			else
				dir++;
			break;
		case 1:
			// east
			if(j + 1 < SIZE && grid[i][j+1] != '*')
				++j;
			else
				dir++;
			break;
		case 2:
			// south
			if(i + 1 < SIZE && grid[i+1][j] != '*')
				++i;
			else
				dir++;
			break;
		case 3:
			// west
			if(j > 0 && grid[i][j-1] != '*')
				--j;
			else
				dir = 0;
			break;
	}
}

int main()
{
	int fi, fj, ci, cj, fd=0, cd=0,result=0, bound=SIZE * SIZE * 8;

	freopen("ttwo.in", "r",stdin);
	freopen("ttwo.out", "w",stdout);
	
	for(int i=0; i < SIZE; ++i)
	{
		cin >> grid[i];
		for(int j=0; j < SIZE; ++j)
		{
			if(grid[i][j] == 'C')
			{
				ci = i;
				cj = j;
			}
			else if(grid[i][j] == 'F')
			{
				fi = i;
				fj = j;
			}
		}
	}

	
	while(!(fi == ci && fj == cj) && result <= bound)
	{
		move(fi,fj,fd);
		move(ci,cj,cd);
		result++;
	}

	if(result > bound)
		result = 0;
	cout << result << endl;

	return 0;
}