#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 30007;

int n, m;
int head[N];
struct node
{
	int to, next;
	int w;
}edge[N];

void addEdge(int a, int b, int w, int k)
{
	edge[k].to = b;
	edge[k].w = w;
	edge[k].next = head[a];
	head[a] = k;
}

void createGraph()
{
	scanf("%d", &n);
	memset(head, 0, sizeof(head));
	m = n-1;
	int a, b, w;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &a, &b, &w);
		addEdge(a, b, w, i*2-1);
		addEdge(b, a, w, i*2);
	}
}

int dist[N];
void dfs(int p, int u, int d)
{
	dist[u] = d;
	for (int k = head[u]; k != 0; k = edge[k].next)
		if (edge[k].to != p)
			dfs(u, edge[k].to, d + edge[k].w);
}

int getDiameter()
{
	dfs(0, 1, 0);
	int u = std::max_element(dist+1, dist+n+1) - dist;
	dfs(0, u, 0);
	return *std::max_element(dist+1, dist+n+1);
}

int main(int argc, char const *argv[])
{
	freopen("p_9.in", "r", stdin);
	createGraph();
	int len = getDiameter();
	printf("%d\n", len*10 + len*(len+1)/2);
	return 0;
}