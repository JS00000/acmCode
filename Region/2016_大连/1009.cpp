#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAXN 200007
#define MAXM 100000
#define MAX_LENGTH 10000000

typedef long long LL;

using namespace std;


int n, nn, m, s, not_sure;
int head[MAXN];
int dis[MAXN];
int a[MAXM];
bool a_flag[MAXM];
struct EdgeNode
{
	int to;
	int next;
};
EdgeNode edge[MAXM];

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		memset(head, 0, (n+1)*sizeof(int));
		memset(edge, 0, (m*2+1)*sizeof(EdgeNode));
		for (int i = 0; i < n+1; ++i)
			dis[i] = 1;
		for (int k = 1; k <= m; ++k)
		{
			int i, j;
			scanf("%d%d", &i, &j);
			edge[k*2-1].to = j;
			edge[k*2-1].next = head[i];
			head[i] = k*2-1;
			edge[k*2].to = i;
			edge[k*2].next = head[j];
			head[j] = k*2;
		}
		scanf("%d", &s);
		dis[s] = 0;
		not_sure = 0;
		for (int k = head[s]; k != 0; k = edge[k].next)
		{
			dis[edge[k].to] = MAX_LENGTH;
			a[not_sure] = edge[k].to;
			not_sure++;
		}


		memset(a_flag, 0, not_sure*sizeof(bool));
		for (int p = 0; p < not_sure; ++p)
		{
			for (int i = 1; i <= n; ++i)
			{
				if (i == a[p]) continue;
				bool flag = 1;
				for (int k = head[i]; k != 0; k = edge[k].next)
				{
					if (edge[k].to == a[p])
					{
						flag = 0;
						break;
					}
				}
				if (flag)
				{
					if (dis[i] == 1)
					{
						dis[a[p]] = 2;
						a_flag[p] = 1;
						break;
					}
				}
			}
		}
		int temp = not_sure;
		not_sure = 0;
		for (int i = 0; i < temp; ++i)
		{
			if (!a_flag[i])
			{
				a[not_sure] = a[i];
				not_sure++;
			}
		}

		nn = min(110, n);
		while(not_sure)
		{
			// for (int i = 0; i < not_sure; ++i)
			// {
			// 	printf("%d ", a[i]);
			// }
			// printf("\n");

			int not_sure_dup = not_sure;
			memset(a_flag, 0, not_sure*sizeof(bool));
			for (int p = 0; p < not_sure_dup; ++p)
			{
				for (int i = 1; i <= nn; ++i)
				{
					if (i == a[p]) continue;
					bool flag = 1;
					for (int k = head[i]; k != 0; k = edge[k].next)
					{
						if (edge[k].to == a[p])
						{
							flag = 0;
							break;
						}
					}
					if (flag)
					{
						if (dis[i]+1 < dis[a[p]])
						{
							dis[a[p]] = dis[i]+1;
							// printf("update from %d: dis[%d]=%d\n", i, a[p], dis[a[p]]);
							a_flag[p] = 1;
						}
					}
				}
			}
			not_sure = 0;
			for (int i = 0; i < not_sure_dup; ++i)
			{
				if (!a_flag[i])
				{
					a[not_sure] = a[i];
					not_sure++;
				}
			}
		}
		if (s != 1)
		{
			printf("%d", (dis[1] == MAX_LENGTH) ? -1:dis[1]);
			for (int i = 2; i <= n; ++i)
			{
				if (i != s)
				{
					if (dis[i] == MAX_LENGTH)
					{
						printf(" -1");
					}
					else
					{
						printf(" %d", dis[i]);
					}
				}
			}
		}
		else
		{
			printf("%d", (dis[2] == MAX_LENGTH) ? -1:dis[2]);
			for (int i = 3; i <= n; ++i)
			{
				if (dis[i] == MAX_LENGTH)
				{
					printf(" -1");
				}
				else
				{
					printf(" %d", dis[i]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}