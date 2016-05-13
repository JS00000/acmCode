#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAXN 1007
#define MAXM 1000007

typedef long long LL;

using namespace std;


int n, m;
int head[MAXN];
struct EdgeNode
{
	int to;
	int w;
	int next;
	bool select;
};
EdgeNode edge[MAXM];

void graphCreat()
{
	cin >> n >> m;
	memset(head, 0, (n+1)*sizeof(int));
	memset(edge, 0, (m+1)*sizeof(EdgeNode));
	for (int k = 1; k <= m; ++k)
	{
		int i, j, w;
		cin >> i >> j >> w;
		edge[k].to = j;
		edge[k].w = w;
		edge[k].select = false;
		edge[k].next = head[i];
		head[i] = k;
	}
}

struct DisjointSet
{
	std::vector<int> father, rank;
	DisjointSet(int n) : father(n), rank(n)
	{
		for (int i = 0; i < n; ++i)
			father[i] = i;
	}

	int find(int v)
	{
		return father[v] = father[v]==v ? v : find(father[v]);
	}

	void merge(int x, int y)
	{
		int a = find(x), b = find(y);
		if (rank[a] < rank[b])
		{
			father[a] = b;
		}
		else
		{
			father[b] = a;
			if (rank[b]==rank[a])
			{
				++rank[a];
			}
		}
	}
};

bool cmp(EdgeNode a, EdgeNode b)
{
	return a.w < b.w ? 1 : (a.w == b.w ? a.to < b.to : 0);
}

void kruskal()
{
	DisjointSet dis(n);
	sort(edge+1, edge+m+1, cmp);
	int j = 0, x, y;
	for (int i = 1; i <= n; ++i)
	{
		if (j == n - 1) break;
		for (int k = head[i]; k != 0; k = edge[k].next)
		{
			if (j == n - 1) break;
			x = dis.find(i);
			y = dis.find(edge[k].to);
			if (x != y)
			{
				dis.merge(x, y);
				j++;
				edge[k].select = true;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int k = head[i]; k != 0; k = edge[k].next)
		{
			if (edge[k].select)
			{
				cout << i << " " << edge[k].to << endl;
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	freopen("text.in", "r", stdin);
	graphCreat();
	kruskal();
	return 0;
}
