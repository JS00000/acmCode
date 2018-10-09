#include <cmath>
#include <cstdio>
#include <cstring>
#define maxn 100
using namespace std;

int maxi[maxn], mini[maxn];

int dfs(int a[], int m, char c)
{
	if (m == 1) return a[0];
	char resp[10];
	int i;
	for (i = 0; i < m>>1; i++)
	{
		printf("? %d %d\n", a[i*2], a[i*2+1]);
		fflush(stdout);
		scanf("%s", resp);
		if (resp[0] == c) a[i] = a[i*2];
		else a[i] = a[i*2+1];
	}
	if (m & 1) a[i++] = a[m-1];
	return dfs(a, i, c);
}

void solve(int n)
{
	if (n == 1)
	{
		printf("! 1 1\n");
		fflush(stdout);
		return;
	}
	char resp[10];
	int i, xmin, xmax, imax, imin;
	for (i = 0; i < n>>1; i++)
	{
		printf("? %d %d\n", i*2+1, i*2+2);
		fflush(stdout);
		scanf("%s", resp);
		if (resp[0] == '<')
		{
			maxi[i] = i*2+2;
			mini[i] = i*2+1;
		}
		else
		{
			maxi[i] = i*2+1;
			mini[i] = i*2+2;
		}
	}
	imax = imin = i;
	if (n & 1)
	{
		printf("? %d %d\n", mini[0], n);
		fflush(stdout);
		scanf("%s", resp);
		if (resp[0] == '<') maxi[imax++] = n;
		else mini[imin++] = n;
	}
	xmin = dfs(mini, imin, '<');
	xmax = dfs(maxi, imax, '>');
	printf("! %d %d\n", xmin, xmax);
	fflush(stdout);
}

int main()
{
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		solve(n);
	}
	return 0;
}
