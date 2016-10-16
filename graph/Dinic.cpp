#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 507
#define maxm 42007
using namespace std;

int n, m;
int head[maxn];
struct node
{
	int next, to, f;
}edge[maxm];
int level[maxn];
bool makelevel(int s, int t)
{
	memset(level, 0, sizeof(level));
	level[s] = 1;
	int que[maxn];
	int iq = 0;
	que[iq++] = s;
	int i, k;
	int top;
	for(i = 0; i < iq; i++)
	{
		top = que[i];
		if (top == t) return true;
		for(k = head[top]; k != -1; k = edge[k].next)
		{
			if (!level[edge[k].to] && edge[k].f)
			{
				que[iq++] = edge[k].to;
				level[edge[k].to] = level[top] + 1;
			}
		}
	}
	return false;
}

int DFS(int now, int maxf, int t)
{
	if (now == t) return maxf;
	int ret = 0, f;
	int k;
	for (k = head[now]; k != -1; k = edge[k].next)
	{
		if (edge[k].f && level[edge[k].to] == level[now] + 1)
		{
			f = DFS(edge[k].to, min(maxf-ret, edge[k].f), t);
			edge[k].f -= f;
			edge[k^1].f += f;
			ret += f;
			if (ret == maxf) return ret;
		}
	}
	return ret;
}
int DINIC(int s, int t)
{
	int ans = 0;
	while(makelevel(s, t)) ans += DFS(s, ~0u>>1, t);
	return ans;
}
int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	int u, v, f;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &u, &v, &f);
		edge[i*2].f = f;
		edge[i*2].to = v;
		edge[i*2].next = head[u];
		head[u] = i*2;
		edge[i*2+1].f = 0;
		edge[i*2+1].to = u;
		edge[i*2+1].next = head[v];
		head[v] = i*2+1;
	}
	printf("%d\n", DINIC(1, n));
	return 0;
}
