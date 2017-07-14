#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1001;
const int M = 10;

int n, m, q;
int f[N][1 << M];
int w[N];

int getSum(int x)
{
	int ret = 0;
	while(x)
	{
		if (x & 1) ret++;
		x >>= 1;
	}
	return ret;
}


int main(int argc, char const *argv[])
{
	// freopen("in.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &q);
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; ++i) scanf("%d", w+i);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = (1 << m) - 1; j >= 0; --j)
		{
			int mid = j >> 1;
			if (getSum(j >> 1) < q && (j & 1)) f[i][j] = std::max(f[i-1][mid], f[i-1][mid + (1 << (m - 1))]) + w[i];
			else f[i][j] = std::max(f[i-1][mid], f[i-1][mid + (1 << (m - 1))]);
		}
	}
	int ans = 0;
	for (int j = 0; j < 1 << m; ++j)
		if (ans < f[n][j]) ans = f[n][j];
	printf("%d\n", ans);
	return 0;
}
