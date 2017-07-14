#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 3007
#define maxm 10000
using namespace std;


int n, m, edge_idx;
int head[maxn];
struct node
{
	int to, next, c, w;
}edges[maxm*10];

void add_edge(int u, int v, int c, int w)
{
	edges[edge_idx].c = c;
	edges[edge_idx].w = w;
	edges[edge_idx].to = v;
	edges[edge_idx].next = head[u];
	head[u] = edge_idx++;
}

void build_graph()
{
	memset(head, -1, sizeof(head));
	edge_idx = 0;
	int a[maxn], b[maxn], p, s;
	scanf("%d%d%d", &n, &p, &s);
	add_edge(3, 2, p, 0);
	add_edge(2, 3, 0, 0);
	add_edge(4, 2, s, 0);
	add_edge(2, 4, 0, 0);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	for (int i = 1; i <= n; i++) scanf("%d", b+i);
	for (int i = 1; i <= n; i++)
	{
		add_edge(1, i+4, 1, 0);
		add_edge(i+4, 1, 0, 0);
		add_edge(i+4, 3, 1, a[i]);
		add_edge(3, i+4, 0, -a[i]);
		add_edge(i+4, 4, 1, b[i]);
		add_edge(4, i+4, 0, -b[i]);
	}
}


int dis[maxn], load[maxm], pre[maxn];
bool flag[maxn];
// dis:距离数组, load:前驱边, pre:前驱点
// flag:点是否入队
bool spfa(int start, int end, int N)
{
	int que[maxn*10], qout, qin;
	memset(flag, 0, sizeof(flag));
	memset(load, -1, sizeof(load));
	memset(pre, -1, sizeof(pre));
	for (int i = 0; i <= N; i++) dis[i] = ~(~0u>>1);
	qin = qout = 0;
	que[qin++] = start;
	dis[start] = 0;
	flag[start] = 1;
	while(qin != qout)
	{
		int e = que[qout++];
		flag[e] = false;
		for (int k = head[e]; k != -1; k = edges[k].next)
		{
			if (edges[k].c)
			{
				int ne = edges[k].to;
				if (dis[ne] < dis[e] + edges[k].w)
				{
					dis[ne] = dis[e] + edges[k].w;
					pre[ne] = e;
					load[ne] = k;
					if (!flag[ne])
					{
						flag[ne] = 1;
						que[qin++] = ne;
					}
				}
			}
		}
	}
	if (dis[end] == ~(~0u>>1)) return 0;
	return 1;
}

int max_cost_flow(int start, int end, int N)
{
	int u, mini, ans_flow = 0, ans_cost = 0;
	while(spfa(start, end, N))
	{
		u = end;
		mini = ~0u>>1;
		while(pre[u] != -1)
		{
			mini = min(mini, edges[load[u]].c);
			u = pre[u];
		}
		u = end;
		while(pre[u] != -1)
		{
			edges[load[u]].c -= mini;
			edges[load[u]^1].c += mini;
			u = pre[u];
		}
		ans_cost += dis[end]*mini;
		ans_flow += mini;
	}
	return ans_cost;
}


int main()
{
	build_graph();
	printf("%d\n", max_cost_flow(1, 2, n+4));
	for (int i = 1; i <= n; i++)
	{
		for (int k = head[i+4]; k != -1; k = edges[k].next)
			if (edges[k].to == 3 && edges[k].c == 0) printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		for (int k = head[i+4]; k != -1; k = edges[k].next)
			if (edges[k].to == 4 && edges[k].c == 0) printf("%d ", i);
	}
	printf("\n");
	return 0;
}
