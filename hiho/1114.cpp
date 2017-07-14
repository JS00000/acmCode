// 扫雷 simple
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

bool check(int a[], int p[], bool p1, int n)
{
	p[0] = 0;
	p[1] = p1;
	for (int i = 1; i < n; ++i)
	{
		p[i+1] = a[i] - p[i] - p[i-1];
		if (p[i+1] < 0 || p[i+1] > 1) return 0;
	}
	if (p[n-1] + p[n] != a[n]) return 0;
	return 1;
}

void solve(int a[], int n)
{
	int p[n+2], ans[n+2];
	for (int i = 1; i <= n; ++i) ans[i] = 3;
	if (check(a, p, 0, n))
		for (int i = 1; i <= n; ++i)
			ans[i] = ans[i] & (p[i]?1:2);
	if (check(a, p, 1, n))
		for (int i = 1; i <= n; ++i)
			ans[i] = ans[i] & (p[i]?1:2);
	int count1 = 0, count2 = 0;
	for (int i = 1; i <= n; ++i) if (ans[i] == 1) count1++; else if (ans[i] == 2) count2++;
	printf("%d", count1);
	for (int i = 1; i <= n; ++i) if (ans[i] == 1) printf(" %d", i);
	printf("\n%d", count2);
	for (int i = 1; i <= n; ++i) if (ans[i] == 2) printf(" %d", i);
	printf("\n");

}


int main()
{
	int a[maxn];
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", a+i);
		solve(a, n);
	}
	return 0;
}
