#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

#define MAXN 100007
#define MAXM 100007

using namespace std;


struct EdgeNode
{
	int to;
	int next;
};

int n, m, i, j, k, t;
int head[MAXN] = {0};
int indegree[MAXN] = {0};
EdgeNode edge[MAXM];

int q[MAXN];
bool s[MAXN] = {0} ;

int f[MAXN];

void topo()
{
	int iq = 0;
	priority_queue<int> pq;
	for (int i = 1; i <=n ; ++i)
	{
		if (indegree[i]==0)
		{
			pq.push(i);
		}
	}
	while(!pq.empty())
	{
		int it = pq.top();
		q[iq++] = it;
		pq.pop();
		for (int k = head[it]; k!=0; k = edge[k].next)
		{
			indegree[edge[k].to]--;
			if (indegree[edge[k].to]==0)
			{
				pq.push(edge[k].to);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		memset(s, 0, (n + 1) * sizeof(bool));
		memset(head, 0, (n + 1) * sizeof(int));
		memset(indegree, 0, (n + 1) * sizeof(int));
		for (i = 1; i <= m; ++i)
		{
			edge[i].next = 0;
		}
		for (k = 1; k <= m; ++k)
		{
			scanf("%d %d", &i, &j);
			edge[k].to = j;
			edge[k].next = head[i];
			head[i] = k;
			indegree[j]++;
		}
		topo();

		int minx = q[0];
		long long ans = minx;
		for (int i = 1; i < n; ++i)
		{
			if (q[i] < minx)
				minx = q[i];
			ans += minx;
		}
		printf("%lld\n", ans);
	}
	return 0;
}