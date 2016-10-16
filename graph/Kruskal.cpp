// Kruskal
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAXN 1007
#define MAXM 1000007

typedef long long LL;

using namespace std;

struct DisjointSet
{
	std::vector<int> father, rank;
	DisjointSet(int n) : father(n+1), rank(n+1)
	{
		for (int i = 0; i <= n; ++i)
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

int n, m;
struct EdgeNode
{
	int a, b;
	int w;
	bool select;
} edge[MAXM];

void graphCreat()
{
	cin >> n >> m;
	memset(edge, 0, (m+1)*sizeof(EdgeNode));
	for (int k = 1; k <= m; ++k)
	{
		int i, j, w;
		cin >> i >> j >> w;
		edge[k].a = i;
		edge[k].b = j;
		edge[k].w = w;
		// edge[k*2-1].a = i;
		// edge[k*2-1].b = j;
		// edge[k*2-1].w = w;
		// edge[k*2].a = j;
		// edge[k*2].b = i;
		// edge[k*2].w = w;
	}
	// m *= 2;
}


bool cmp(EdgeNode a, EdgeNode b)
{
	return a.w < b.w ? 1 : (a.w == b.w ? (a.a < b.a ? 1 : a.b < b.b) : 0);
}
void kruskal()
{
	DisjointSet dis(n);
	sort(edge+1, edge+m+1, cmp);
	int j = 0, x, y;
	for (int i = 1; i <= m; ++i)
	{
		if (j == n - 1) break;
		x = dis.find(edge[i].a);
		y = dis.find(edge[i].b);
		if (x != y)
		{
			dis.merge(x, y);
			j++;
			edge[i].select = true;
			// edge[((i+1)^1)-1].select = true;
			cout << edge[i].a << " " << edge[i].b << endl;
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
