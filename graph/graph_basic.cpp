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
		edge[k].next = head[i];
		head[i] = k;
	}
}

void graphTraverse()
{
	for (int i = 1; i <= n; i++)
	{
		for (int k = head[i]; k != 0; k = edge[k].next)
		{
			cout << i << " " << edge[k].to << " " << edge[k].w << endl;
		}
	}
}


bool s[MAXN] = {0};
void dfs(int x)
{
	s[x] = 1;
	cout << x << " ";
	for (int k = head[x]; k != 0; k = edge[k].next)
	{
		if (!s[edge[k].to])
		{
			dfs(edge[k].to);
		}
	}
}

void bfs(int x)
{
	int queue[n+1];
	int iq = 1;
	queue[iq++] = x;
	s[x] = 1;
	int i = 1;
	while(i<iq)
	{
		cout << queue[i] << " ";
		for (int k = head[queue[i]]; k != 0; k = edge[k].next)
		{
			if (!s[edge[k].to])
			{
				s[edge[k].to] = 1;
				queue[iq++] = edge[k].to;
			}
		}
		i++;
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	graphCreat();
	graphTraverse();
	memset(s, 0, (n+1)*sizeof(bool));
	dfs(1);printf("\n");
	memset(s, 0, (n+1)*sizeof(bool));
	bfs(1);printf("\n");
	return 0;
}
