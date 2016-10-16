// 二分图最大匹配 匈牙利算法DFS版
#include <cstdio>
#include <cstring>

const int N =  300;

bool bmap[N][N];
bool bmask[N];
int nx, ny, m;
int cx[N];
int cy[N];


void createGraph()
{
	scanf("%d%d%d", &nx, &ny, &m);
	memset(bmap, 0, sizeof(bmap));
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &a, &b);
		bmap[a][b] = 1;
	}
}

int findpath(int u)
{
	for (int i = 1; i <= ny; ++i)
	{
		if (bmap[u][i] && !bmask[i])
		{
			bmask[i] = 1;
			if (cy[i] == 0 || findpath(cy[i]))
			{
				cy[i] = u;
				cx[u] = i;
				return 1;
			}
		}
	}
	return 0;
}

int maxMatch()
{
	int res = 0;
	memset(cx, 0, sizeof(cx));
	memset(cy, 0, sizeof(cy));
	for (int i = 1; i <= nx; ++i)
	{
		if (cx[i] == 0)
		{
			for (int j = 1; j <= ny; ++j)
				bmask[j] = 0;
			res += findpath(i);
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	freopen("match.in", "r", stdin);
	createGraph();
	printf("%d\n", maxMatch());
	for (int i = 1; i <= nx; ++i)
		printf("%d ", cx[i]);
	printf("\n");
	return 0;
}