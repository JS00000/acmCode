#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

#define maxn 1007
#define maxq 100007

using namespace std;

int p[maxn];
int head[maxn];
int qhead[maxn];
int dist[maxn];
struct node
{
	int to, w, next, lca;
}edge[maxn], qedge[maxq];

struct qnode
{
	int a, b;
}qq[maxq];

int qmap[maxn][maxn];

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
bool visit[maxn];
void LCA(int u, int d)
{
	p[u] = u;
	dist[u] = d;
	int k;
	visit[u] = true;
	for (k = head[u]; k != 0; k = edge[k].next)
	{
		if (!visit[edge[k].to])
		{
			LCA(edge[k].to, d + edge[k].w);
			p[edge[k].to] = u;
		}
	}
	for (k = qhead[u]; k != 0; k = qedge[k].next)
	{
		if (visit[qedge[k].to])
		{
			qedge[k].lca = find(qedge[k].to);
			qedge[((k+1)^1)-1].lca = qedge[k].lca;
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("Tarjan.in", "r", stdin);
	int n, m, q, a, b, w;
	cin >> n >> m;
	memset(visit, 0, sizeof(visit));
	memset(head, 0, sizeof(head));
	memset(qhead, 0, sizeof(qhead));
	memset(dist, 0, sizeof(dist));
	memset(qmap, 0, sizeof(qmap));
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b >> w;
		edge[i*2-1].to = b;
		edge[i*2-1].w = w;
		edge[i*2-1].lca = 0;
		edge[i*2-1].next = head[a];
		head[a] = i*2-1;
		edge[i*2].to = a;
		edge[i*2].w = w;
		edge[i*2].lca = 0;
		edge[i*2].next = head[b];
		head[b] = i*2;
	}
	cin >> q;
	for (int i = 1; i <= q; ++i)
	{
		cin >> a >> b;
		qedge[i*2-1].to = b;
		qedge[i*2-1].next = qhead[a];
		qhead[a] = i*2-1;
		qedge[i*2].to = a;
		qedge[i*2].next = qhead[b];
		qhead[b] = i*2;
		qq[i].a = a;
		qq[i].b = b;
	}
	LCA(1, 0);
	for (int i = 1; i <= n; ++i)
	{
		for (int k = qhead[i]; k != 0; k = qedge[k].next)
		{
			// cout << i << " " << qedge[k].to << ": " << qedge[k].lca << endl;
			qmap[i][qedge[k].to] = qedge[k].lca;
			qmap[qedge[k].to][i] = qedge[k].lca;
		}
	}
	for (int i = 1; i <= q; ++i)
	{
		cout << dist[qq[i].a] + dist[qq[i].b] - 2 * dist[qmap[qq[i].a][qq[i].b]] << endl;
	}
	return 0;
}