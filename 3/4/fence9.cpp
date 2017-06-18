/*
ID:ilimugu1
LANG:C++
PROB:fence9
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct
{
    double x, y;
} Vector;

Vector multiplyWithConstant(const Vector& vec, double c)
{
    Vector result;
    result.x = vec.x;
    result.y = vec.y;

    result.x *= c;
    result.y *= c;
    return result;
}

int calculate(Vector& roof, bool borderIsInclusive)
{
	int result = 0;

    for(int i = 1; i < roof.x; ++i)
    {
        double factor = (i / (double)roof.x);
        Vector v = multiplyWithConstant(roof, factor);
        if(v.y < 0)
            v.y = -v.y;
        v.y = trunc(1000000 * v.y) / 1000000;
        result += (borderIsInclusive ? int(floor(v.y)) :
									   max(0, int(ceil(v.y) - 1)));
    }
	
	return result;
}

int main()
{
    int n, m, p, result = 0;

    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);

    cin >> n >> m >> p;

    Vector roof;
    roof.x = n;
    roof.y = m;

	result = calculate(roof, false);

	roof.x = abs(p - n);
    roof.y = m;

	if(p > n)
	{
		result += calculate(roof, false);
		if(n > 0)
			result += (m-1);
	}
	else
		result -= calculate(roof, true);

    cout << result << endl;
	
	return 0;
}
