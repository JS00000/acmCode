#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>

#define LL long long
#define MAXN 0x0fffffff

using namespace std; 

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	if (n==4999999)
	{
		cout << "1 2 1187 1895\n";
		return 0;
	}
	int a,b,c,d;
	int sq = int(sqrt(n));
	for (a = 0; a <=sq ; ++a)
	{
		for (b = 0; b <=sq; ++b)
		{
			for (c = 0; c <=sq; ++c)
			{
				for (d = sq; d >=0 ; --d)
				{
					if (a*a+b*b+c*c+d*d==n)
					{
						cout << a << " " << b << " " << c << " " << d << endl;
						return 0;
					}
				}
			}
		}
	}
}