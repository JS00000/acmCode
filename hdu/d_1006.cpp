#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>

#define maxn 100007
#define maxq 100007

using namespace std;

int head[maxn];
bool imp[maxn];
int qm[maxn];
struct node
{
	int to, next;
}edge[maxn];

int n, m, q, a, b, temp, ans;

bool visit[maxn];
int son[maxn];
int fa[maxn];
int queue[maxn];
void bfs(int x)
{
	int iq = 1;
	queue[iq++] = x;
	visit[x] = 1;
	int i = 1;
	int sonn = 0;
	int son_flag = 0;
	for (int k = head[queue[i]]; k != 0; k = edge[k].next, sonn++)
	{
		son[sonn] = 0;
		fa[edge[k].to] = sonn;
		queue[iq++] = edge[k].to;
		if (!imp[edge[k].to])
		{
			son[fa[edge[k].to]]++;
			son_flag++;
		}
		if (son_flag == 2)
		{
			i = iq;
			ans++;
			break;
		}
		printf("%d Fuxx?? %d %d %d\n", ans, queue[i], edge[k].to, !imp[edge[k].to]);
	}
	while(i<iq)
	{
		for (int k = head[queue[i]]; k != 0; k = edge[k].next)
		{
			if (!visit[edge[k].to])
			{
				visit[edge[k].to] = 1;
				fa[edge[k].to] = fa[queue[i]];
				queue[iq++] = edge[k].to;
				if (son[fa[edge[k].to]] == 0 && !imp[edge[k].to])
				{
					son[fa[edge[k].to]]++;
					son_flag++;
				}
				if (son_flag == 2)
				{
					i = iq;
					ans++;
					break;
				}
			}
			printf("%d cc?? %d %d\n", ans, queue[i], edge[k].to);
		}
		i++;
	}
	for (i = 1; i <= iq; ++i) visit[i] = 0;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &q);
		memset(head, 0, (n+2)*sizeof(int));
		memset(imp, 0, (n+2)*sizeof(int));
		memset(visit, 0, (n+2)*sizeof(bool));
		for (int i = 1; i <= n-1; ++i)
		{
			scanf("%d%d", &a, &b);
			edge[i*2-1].to = b;
			edge[i*2-1].next = head[a];
			head[a] = i*2-1;
			edge[i*2].to = a;
			edge[i*2].next = head[b];
			head[b] = i*2;
		}
		for (int i = 1; i <= q; ++i)
		{
			scanf("%d", &m);
			ans = n - m;
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", qm+j);
				imp[qm[j]] = 1;
			}
			for (int j = 0; j < m; ++j) bfs(qm[j]);
			printf("%d\n", ans);
		}
	}
	return 0;
}
