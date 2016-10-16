// SPFA
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxn 1007
#define maxm 10007

using namespace std;

int n, m;
int head[maxn];
struct node
{
	int to, next;
	int w;
}edge[maxm];

void creatGraph()
{
	cin >> n >> m;
	memset(head, 0, sizeof(head));
	int a, b, w;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b >> w;
		edge[i].to = b;
		edge[i].w = w;
		edge[i].next = head[a];
		head[a] = i;
	}
}


int dist[maxn];
bool SPFA(int s)
{
	bool visit[maxn];
	int queue[maxn];
	int outque[maxn];
	int iq = 0;
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = 1000000000;
	}
	memset(visit, 0, sizeof(visit));
	memset(outque, 0, sizeof(outque));
	queue[iq++] = s;
	visit[s] = 1;
	dist[s] = 0;
	int i = 0;
	while(i != iq)
	{
		int top = queue[i];
		visit[top] = 0;
		outque[top]++;
		if (outque[top] > n) return false;
		for (int k = head[top]; k != 0; k = edge[k].next)
		{
			if (dist[edge[k].to] - edge[k].w > dist[top])
			{
				dist[edge[k].to] = dist[top] + edge[k].w;
				// printf("%d ", dist[edge[k].to]);
				if (!visit[edge[k].to])
				{
					visit[edge[k].to] = 1;
					queue[iq++] = edge[k].to;
					if (iq >= n) iq = 0;
				}
			}
		}
		i++;
		if (i >= n) i = 0;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	freopen("SPFA.in", "r", stdin);
	creatGraph();
	if (SPFA(1)) printf("OK\n");
	for (int i = 1; i <= n; ++i)
		printf("%d ", dist[i]);
	printf("\n");
	return 0;
}