// 求欧拉回路
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10001
#define MAXM 1000007

using namespace std;

struct EdgeNode
{
	int to;
	int next;
};

int head[MAXN] = {0};
EdgeNode edge[MAXM];
bool s[MAXN] = {0} ;

int ans[MAXM];
int ansi = 0;
bool vis[MAXM];

void dfs(int now)
{
	int k;
	for (int k = head[now]; k != 0; k = edge[k].next)
	{
		if (!vis[k])
		{
			vis[k] = 1;
			vis[((k-1)^1) + 1] = 1;

			
			dfs(edge[k].to);
			ans[ansi++] = k;
		}
	}
}


int main(int argc, char const *argv[])
{
	freopen("text.in", "r", stdin);
	int n, m, i, j;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		head[i] = 0;
	}
	for (int k = 1; k <= m; ++k)
	{
		cin >> i >> j;

		edge[k*2-1].to = j;
		edge[k*2-1].next = head[i];
		head[i] = k*2-1;

		edge[k*2].to = i;
		edge[k*2].next = head[j];
		head[j] = k*2;

		vis[k*2-1] = 0;
		vis[k*2] = 0;
	}

	dfs(1);
	for (int i = ansi - 1; i >= 0; --i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
