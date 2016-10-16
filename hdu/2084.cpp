#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define maxn 107
using namespace std;

int n;
int a[maxn][maxn];

int main()
{
	memset(a, 0, sizeof(a));
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= i; ++j) scanf("%d", &a[i][j]);
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= i; j++)
				a[i][j] = a[i][j] + max(a[i-1][j], a[i-1][j-1]);
		int ans = -1;
		for (int i = 1; i <= n; i++)
			if (ans < a[n][i]) ans = a[n][i];
		printf("%d\n", ans);
	}
}
