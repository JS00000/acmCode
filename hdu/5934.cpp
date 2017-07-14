// 强连通 kosaraju 算法
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int N = 1007;
const int M = 1000007;

int n, m, edge_idx;
int head[N], head2[N];
struct node
{
	int to, next, from, next2;
}edge[M];

void addEdge(int a, int b)
{
	edge[edge_idx].to = b;
	edge[edge_idx].next = head[a];
	head[a] = edge_idx;
	edge[edge_idx].from = a;
	edge[edge_idx].next2 = head2[b];
	head2[b] = edge_idx++;
}

struct bomb
{
	ll x, y, r, c;
}bb[N];

bool reach(bomb a, bomb b)
{
	if ((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y) <= a.r*a.r) return 1;
	else return 0;
}

void createGraph()
{
	memset(head, -1, sizeof(head));
	memset(head2, -1, sizeof(head2));
	edge_idx = 0;
	scanf("%d", &n);
	int x, y, r, c;
	for (int i = 1; i <= n; ++i) scanf("%lld%lld%lld%lld", &bb[i].x, &bb[i].y, &bb[i].r, &bb[i].c);
	for (int i = 1 ;i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && reach(bb[i], bb[j]))
				addEdge(i, j);
}

int sig;
bool flag[N];
int num[N];
int col[N];
void dfs1(int u)
{
	flag[u] = 1;
	for (int k = head[u]; k != -1; k = edge[k].next)
		if (!flag[edge[k].to]) dfs1(edge[k].to);
	num[++sig] = u;
}

void dfs2(int u)
{
	flag[u] = 1;
	col[u] = sig;
	for (int k = head2[u]; k != -1; k = edge[k].next2)
		if (!flag[edge[k].from])
			dfs2(edge[k].from);
}

int kosaraju()
{
	sig = 0;
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= n; ++i)
		if (!flag[i])
			dfs1(i);
	sig = 0;
	memset(flag, 0, sizeof(flag));
	for (int i = n; i > 0; i--)
		if (!flag[num[i]])
		{
			sig++;
			dfs2(num[i]);
		}
	return sig;
}

ll calc(int c)
{
	ll ans[c+1], sum = 0;
	bool p[c+1];
	for (int i = 1; i <= c; ++i) ans[i] = ~0u>>1, p[i] = 1;
	for (int i = 1; i <= n; ++i) ans[col[i]] = std::min(ans[col[i]], bb[i].c);
	for (int i = 1; i <= n; ++i)
		for (int k = head[i]; k != -1; k = edge[k].next)
			if (col[i] != col[edge[k].to]) p[col[edge[k].to]] = 0;
	for (int i = 1; i <= c; ++i) if (p[i]) sum += ans[i];
	return sum;
}

int main(int argc, char const *argv[])
{
	// freopen("5934.in", "r", stdin);
	int T, kase = 0;
	scanf("%d", &T);
	while(T--)
	{
		createGraph();
		int c = kosaraju();
		printf("Case #%d: %lld\n", ++kase, calc(c));
	}
	return 0;
}