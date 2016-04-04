// bfs
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 10001
#define MAXM 100001

using namespace std;

struct EdgeNode
{
	int to;
	int w;
	int next;
};

int head[MAXN] = {0};
EdgeNode edge[MAXM];
bool s[MAXN] = {0} ;
void bfs(int x)
{
	int queue[MAXN];
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
	int n, m, i, j, k, w;
	cin >> n >> m;
	for (i = 1; i <= m; ++i)
	{
		edge[i].next = 0;
	}
	for (k = 1; k <= m; ++k)
	{
		cin >> i >> j >> w;
		edge[k].to = j;
		edge[k].w = w;
		edge[k].next = head[i];
		head[i] = k;
	}
	for (i = 1; i <= n; ++i)
	{
		for (k = head[i]; k != 0; k = edge[k].next)
		{
			// cout << i << " " << edge[k].to << " " << edge[k].w << endl;
		}
	}
	bfs(1);
	cin >> n;
	return 0;
}