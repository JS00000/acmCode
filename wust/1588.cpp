#include <iostream>
#include <cstdio>

using namespace std;

int md[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

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

bool ifLeapYear(int y)
{
	if ((y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0))) return 1;
	else return 0;
}

int main(int argc, char const *argv[])
{
	int t, k, n, tot, week;
	cin >> t;
	while(t--)
	{
		cin >> k >> n;
		tot = 184500 * n;
		int needDay = (tot-1) / k + 1;
		int d = 1, m = 4, y = 2016;
		int r = needDay / 728483;
		needDay %= 728483;
		while(needDay)
		{
			d++;
			if (d > md[m-1])
			{
				m++;
				d = 1;
			}
			if (m > 12)
			{
				y++;
				m = 1;
				if (ifLeapYear(y)) md[1] = 29;
				else md[1] = 28;
			}
			if (d == 1 && m == 4) continue;
			week = whatDay(y, m, d);
			if (week == 5 || week == 6) continue;
			needDay--;
		}
		y += r*2800;
		printf("%d/", y);
		if (m < 10)
			printf("0%d/", m);
		else
			printf("%d/", m);
		if (d < 10)
			printf("0%d", d);
		else
			printf("%d", d);
		if (y > 2060)
			printf(", A sad story ==");
		printf("\n");
	}
	return 0;
}