#include <cstdio>
#include <cstring>

const int N = 1007;
const int M = 1000000;
int n, m;
int head[N], head2[N];
struct node
{
	int to, next, from, next2;
}edge[M];

void addEdge(int a, int b, int k)
{
	edge[k].to = b;
	edge[k].next = head[a];
	head[a] = k;
	edge[k].from = a;
	edge[k].next2 = head2[b];
	head2[b] = k;
}

void createGraph()
{
	scanf("%d%d", &n, &m);
	int a, b;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		addEdge(a, b, i);
	}
}

int sig;
bool flag[N];
int num[N];
int col[N];
void dfs1(int u)
{
	flag[u] = 1;
	for (int k = head[u]; k != 0; k = edge[k].next)
		if (!flag[edge[k].to]) dfs1(edge[k].to);
	num[++sig] = u;
}

void dfs2(int u)
{
	flag[u] = 1;
	col[u] = sig;
	for (int k = head2[u]; k != 0; k = edge[k].next2)
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


int main(int argc, char const *argv[])
{
	freopen("con.in", "r", stdin);
	createGraph();
	printf("%d\n", kosaraju());
	for (int i = 1; i <= n; ++i)
		printf("%d ", col[i]);
	printf("\n");
	return 0;
}