#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>

#define MAXN 1007
#define MAXM 1000007

typedef long long LL;

using namespace std;

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

struct node1
{
	int to;
	int next;
};
node1 link[MAXN];
int head1[MAXN];
int end1[MAXN];
int length[MAXN][MAXN];


int n, m;
int mst = 0, secmst = INT_MAX;
struct EdgeNode
{
	int a, b;
	int w;
	bool select;
} edge[MAXM];

bool cmp(EdgeNode a, EdgeNode b)
{
	return a.w < b.w ? 1 : (a.a < b.a ? 1 : a.b < b.b);
}

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
		// edge[k*2].a = j;
		// edge[k*2].b = i;
		// edge[k*2].w = w;
	}
	// m *= 2;
}

void kruskal_sec()
{
	int x, y, j = 0;
	int w,v;
	for (int i = 1; i <= n; ++i)
	{
		link[i].to = i;
		link[i].next = head1[i];
		end1[i] = i;
		head1[i] = i;
	}
	DisjointSet dis(n);
	sort(edge+1, edge+m+1, cmp);
	for (int i = 1; i <= m; ++i)
	{
		if (j == n - 1) break;
		x = dis.find(edge[i].a);
		y = dis.find(edge[i].b);
		if (x != y)
		{
			for (w = head1[x]; w != 0; w = link[w].next)
			{
				for (v = head1[y]; v != 0; v = link[v].next)
				{
					length[link[w].to][link[v].to] = length[link[v].to][link[w].to] = edge[i].w;
				}
			}
			link[end1[y]].next = head1[x];
			end1[y] = end1[x];
			dis.merge(x, y);
			j++;
			edge[i].select = true;
			mst += edge[i].w;
			cout << edge[i].a << " " << edge[i].b << endl;
		}
	}
}


int main(int argc, char const *argv[])
{
	freopen("text.in", "r", stdin);
	graphCreat();
	kruskal_sec();
	for (int i = 1; i <= m; ++i)
	{
		if (!edge[i].select) secmst = min(secmst, mst + edge[i].w - length[edge[i].a][edge[i].b]);
	}
	cout << mst << endl;
	cout << secmst << endl;
	return 0;
}

