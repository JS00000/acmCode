#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

typedef long long LL;
using namespace std;
const int maxn = 107;
const double PI = acos(-1.0);

int n, m;
int mp[maxn][maxn];
int pre[maxn][maxn];

void floyd()
{
	for (int k = 1; k <= n; k++)
		for ( int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (mp[i][j] - mp[k][j] > mp[i][k])
				{
					mp[i][j] = mp[i][k] + mp[k][j];
					pre[i][j] = pre[k][j];
				}
			}
}

int main(int argc, char const *argv[])
{
	freopen("graph.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) mp[i][j] = ~0u>>1, pre[i][j] = i;
		mp[i][i] = 0;
	}
	int u, v, c;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		mp[u][v] = c;
	}
	floyd();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d	", mp[i][j] == ~0u>>1 ? -1 : mp[i][j]);
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d	", pre[i][j]);
		printf("\n");
	}
	scanf("%d%d", &u, &v);
	while(v != u) printf("%d ", v), v = pre[u][v];
	printf("%d\n", u);
	return 0;
}

