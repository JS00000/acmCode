#include <iostream>
#include <cstdio>

using namespace std;
typedef long long LL;

int whatDay(int y, int m, int d)
{
	int ans;
	if (m == 1 || m == 2)
		m += 12, y--;
	if ((y < 1752) || (y == 1752 && m < 9) || (y == 1752 && m == 9 && d < 3))
		ans = (d + 2*m + 3*(m + 1)/5 + y + y /4 + 5) % 7;
	else
		ans = (d + 2*m + 3*(m + 1)/5 + y + y /4 - y/100 + y/400) % 7;
	return ans;
}

int main(int argc, char const *argv[])
{
	int c = 0;
	c = 14406;
	LL t;
	int ly,lm,ld,n,r,next,y,m,d;
	bool flag;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%d %d %d %d", &ly, &lm, &ld, &n);
		r = n / c;
		n %= 14406;
		y = ly;
		m = lm;
		d = ld;
		if (whatDay(y,m,d) == 0) n--;
		while(n)
		{
			d += 10;
			if (d == 31)
			{
				m += 1;
				d = 1;
			}
			if (m == 13)
			{
				y += 1;
				m = 1;
			}
			if (whatDay(y,m,d) == 0) n--;
		}
		printf("%d %d %d\n", r*2800 + y, m, d);
	}
	return 0;
}