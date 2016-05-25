#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>

#define maxn 1007
#define maxm 100007
#define INF 1000000000

using namespace std;

int n, m, s, t, kk;
int head[maxn];
int head1[maxn];
struct node
{
	int to, next;
	int w;
}edge[maxm], edge1[maxm];

void creatGraph()
{
	cin >> n >> m;
	memset(head, 0, sizeof(head));
	memset(head1, 0, sizeof(head1));
	int a, b, w;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b >> w;
		edge[i].to = b;
		edge[i].w = w;
		edge[i].next = head[a];
		head[a] = i;

		edge1[i].to = a;
		edge1[i].w = w;
		edge1[i].next = head1[b];
		head1[b] = i;
	}
	cin >> s >> t >> kk;
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
		dist[i] = INF;
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
		for (int k = head1[top]; k != 0; k = edge1[k].next)
		{
			if (dist[edge1[k].to] - edge1[k].w > dist[top])
			{
				dist[edge1[k].to] = dist[top] + edge1[k].w;
				// printf("%d ", dist[edge1[k].to]);
				if (!visit[edge1[k].to])
				{
					visit[edge1[k].to] = 1;
					queue[iq++] = edge1[k].to;
					if (iq >= n) iq = 0;
				}
			}
		}
		i++;
		if (i >= n) i = 0;
	}
	return true;
}

struct node1
{
	int to;
	// f = g + h
	int g, f;
	bool operator < (const node1 &r) const
	{
		return r.f < f ? 1 : (r.f == f ? r.g < g : 0);
	}
};

int a_star(int start, int end, int k)
{
	int cnt = 0;
	node1 e, ne;
	priority_queue<node1> que;
	if (start == end) k++;
	if (dist[start] == INF) return -1;
	e.to = start;
	e.g = 0;
	e.f = dist[start];
	que.push(e);
	while(!que.empty())
	{
		e = que.top();
		que.pop();
		if (e.to == end) cnt++;
		if (cnt == k) return e.g;
		for (int i = head[e.to]; i != 0; i = edge[i].next)
		{
			ne.to = edge[i].to;
			ne.g = e.g + edge[i].w;
			ne.f = ne.g + dist[ne.to];
			que.push(ne);
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	creatGraph();
	SPFA(t);
	printf("%d\n", a_star(s, t, kk));
	return 0;
}