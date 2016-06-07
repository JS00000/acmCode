#include <cstdio>
#include <algorithm>

int n, m;
int f[100001];
int need[501], value[501];

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d%d", need+i, value+i);
	for (int i = 0; i <= m; ++i) f[i] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			if (j - need[i] > 0)
				f[j] = std::max(f[j], f[j - need[i]] + value[i]);
	int maxx = 0;
	for (int i = 0; i <= m; ++i)
		if (maxx < f[i]) maxx = f[i];
	printf("%d\n", maxx);
	return 0;
}