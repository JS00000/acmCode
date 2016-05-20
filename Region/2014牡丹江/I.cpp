#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;



int main(int argc, char const *argv[])
{
	int t, n, unit;
	string s;
	cin >> t;
	while(t--)
	{
		double h = 0, u;
		int a;
		cin >> n >> s;
		if (s == "bit")
			unit = 2;
		else if (s == "dit")
			unit = 10;

		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			u = a/100.0;
			if (a == 0)
			{
				continue;
			}
			else if (s != "nat")
			{
				h -= u * log(u)/log(unit);
			}
			else h -= u * log(u);
		}
		// cout << h << endl;
		printf("%.12lf\n", h);
	}
	return 0;
}