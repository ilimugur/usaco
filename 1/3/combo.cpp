/*
ID:ilimugu1
PROB:combo
LANG:C++11
*/
#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
	set< pair<int, pair<int, int> > > sols;

    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);

    cin >> n;
    int combos[2][3];
	cin >> combos[0][0] >> combos[0][1] >> combos[0][2];
	cin >> combos[1][0] >> combos[1][1] >> combos[1][2];

	for(int c = 0; c < 2; ++c)
	{
		for(int i = -2; i < 3; ++i)
		{
			for(int j = -2; j < 3; ++j)
			{
				for(int k = -2; k < 3; ++k)
				{
					int tmp1 = combos[c][0]+i, tmp2 = combos[c][1]+j, tmp3 = combos[c][2]+k;
					while(tmp1 > n)
					{
						tmp1 -= n;
					}
					while(tmp1 < 1)
					{
						tmp1 += n;
					}
					while(tmp2 > n)
					{
						tmp2 -= n;
					}
					while(tmp2 < 1)
					{
						tmp2 += n;
					}
					while(tmp3 > n)
					{
						tmp3 -= n;
					}
					while(tmp3 < 1)
					{
						tmp3 += n;
					}
					sols.insert( make_pair(tmp1, make_pair(tmp2, tmp3)));
				}
			}
		}
	}

    cout << sols.size() << endl;

    return 0;
}