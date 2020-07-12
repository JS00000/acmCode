// B
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 101010;
const int MAXS = 101010;
int n;
class Str
{
public:
	int l, r, add;
	bool operator <(const Str &b) const
	{
		if(l >= r && b.l < b.r)
			return false;
		if(l < r && b.l >= b.r)
			return true;
		if(l >= r && b.l >= b.r)
			return r > b.r;
		return l < b.l;
	}
}a[MAXN];
char s[MAXS];
void solve()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		int len = strlen(s);
		a[i].l = a[i].r = a[i].add = 0;
		for(int j = 0; j < len; j++)
		{
			if(s[j] == '(')
				a[i].r++;
			else
			{
				if(a[i].r > 0)
					a[i].r--, a[i].add++;
				else
					a[i].l++;
			}
		}
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	int now = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i].l > now)
			a[i].l = now;
		ans += a[i].l + a[i].add;
		now -= a[i].l;
		now += a[i].r;
	}
	printf("%d\n", ans * 2);
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int t1 = 1; t1 <= T; t1++)
		solve();
	return 0;
}