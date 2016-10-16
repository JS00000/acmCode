// 网络流
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 507;
int map[maxn][maxn], p[maxn];
int n, m, u, v, c;
bool EK_bfs(int start, int end)
{
	queue<int> que;
	bool flag[maxn];
	memset(flag, 0, sizeof(flag));
	memset(p, -1, sizeof(p));
	que.push(start);
	flag[start] = true;
	while(!que.empty())
	{
		int e = que.front();
		if (e == end) return true;
		que.pop();
		for (int i = 1; i <= n; i++)
		{
			if (map[e][i] && !flag[i])
			{
				flag[i] = true;
				p[i] = e;
				que.push(i);
			}
		}
	}
	return false;
}

int EK_max_flow(int start, int end)
{
	int u, ans = 0, mini;
	while(EK_bfs(start, end))
	{
		mini = ~0u>>1;
		u = end;
		while(p[u] != -1)
		{
			mini = min(mini, map[p[u]][u]);
			u = p[u];
		}
		ans += mini;
		u = end;
		while(p[u] != -1)
		{
			map[p[u]][u] -= mini;
			map[u][p[u]] += mini;
			u = p[u];
		}
	}
	return ans;
}

int main()
{
	memset(map, 0, sizeof(map));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		map[u][v] = c;
	}
	printf("%d\n", EK_max_flow(1, n));
	return 0;
}
