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

int n, m, i, j, k, w;
int head[MAXN] = {0};
int indegree[MAXN] = {0};
EdgeNode edge[MAXM];
int queue[MAXN];
bool s[MAXN] = {0} ;

// 一种情况的拓扑排序
void topo()
{
	int iq = 0;
	for (int i = 1; i <=n ; ++i)
	{
		if (indegree[i]==0)
		{
			queue[iq++] = i;
		}
	}
	for (int i = 0; i < iq; ++i)
	{
		for (int k = head[queue[i]]; k!=0; k = edge[k].next)
		{
			indegree[edge[k].to]--;
			if (indegree[edge[k].to]==0)
			{
				queue[iq++] = edge[k].to;
			}
		}
	}
	for (int i = 0; i < iq; ++i)
	{
		cout << queue[i] << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	cin >> n;
	int k = 1;
	for (int i = 1; i <= n; i++)
    {
        int j;
        while(cin >> j && j)
        {
            edge[k].to = j;
            edge[k].next = head[i];
            head[i] = k;
            indegree[j]++;
            k++;
        }
    }
    topo();
	return 0;
}
