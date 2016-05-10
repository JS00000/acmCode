#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int t, m;
	double p;
	cin >> t;
	while(t--)
	{
		cin >> m >> p;
		double ret = 0, base = p;
		for (int i = m; i >= 1; --i)
		{
			ret += base * i;
			base *= p;
		}
		printf("%.6lf\n", ret);
	}
	return 0;
}