#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define MAXN 10001
#define MAXM 50001

using namespace std;

int head[MAXN];
struct edgeNode
{
	int to;
	int w;
	int next;
};
edgeNode edge[MAXM];
int n, m, a, b;

int ans[MAXM];
int ansi = 0;
bool visit[2*MAXM] = {0} ;
void dfs(int now)
{
	for (int k = head[now]; k!=-1 ; k=edge[k].next)
	{
		if (!visit[k])
		{
			visit[k] = 1;
			dfs(edge[k].to);
		}
	}
	ans[ansi++] = now;
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 0; i < n ; ++i)
	{
		head[i] = -1;
	}
	for (int i = 0; i < m ; ++i)
	{
		edge[i].next = -1;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		edge[i*2].to = b;
		edge[i*2].next = head[a];
		head[a] = i*2;
		edge[i*2+1].to = a;
		edge[i*2+1].next = head[b];
		head[b] = i*2+1;
	}
	dfs(1);
	for (int i = 0; i < ansi; ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}