// 最小树形图
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>

#define MAXN 1007
#define MAXM 1000007

typedef long long LL;

using namespace std;

double mp[MAXN][MAXN];

double min_tree_in_oriented_graph(int n, double mp[MAXN][MAXN])
{
	bool visited[MAXN];
	bool flag[MAXN];
	int pre[MAXN];
	double sum = 0;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		flag[i] = false;
		mp[i][i] = INT_MAX;
	}
	pre[0] = 0;
	while(true)
	{
		// 求最短弧集合E0
		for (i = 1; i < n; ++i)
		{
			if (flag[i]) continue;
			pre[i] = i;
			for (j = 0; j < n; j++)
				if (!flag[j] && mp[j][i] < mp[pre[i]][i]) pre[i] = j;
			if (pre[i] == i) return -1;
		}

		// 检查E0
		for (i = 1; i < n; i++)
		{
			if (flag[i]) continue;
			for (j = 0; j < n; j++) visited[j] = false;
			visited[0] = true;
			j = i;
			do
			{
				visited[j] = true;
				j = pre[j];
			} while(!visited[j]);
			//没找到环
			if (!j) continue;
			// 收缩G中的有向环
			i = j;
			do
			{
				sum += mp[pre[j]][j];
				j = pre[j];
			} while(j != i);
			j = i;
			do
			{
				for (k = 0; k < n; k++)
					if (!flag[k] && mp[k][j] < INT_MAX && k != pre[j]) mp[k][j] -= mp[pre[j]][j];
				j = pre[j];
			} while(j != i);
			// 缩点，将整个环缩成i号点，所有与环上的点有关的边转移到点i
			for (j = 0; j < n; j++)
			{
				if (j == i) continue;
				for (k = pre[i]; k != i; k = pre[k])
				{
					if (mp[k][j] < mp[i][j]) mp[i][j] = mp[k][j];
					if (mp[j][k] < mp[j][i]) mp[j][i] = mp[j][k];
				}
			}
			// 标记环上其他的点为被缩掉
			for (j = pre[i]; j != i; j = pre[j]) flag[j] = true;
			// 当前环缩点结束，形成新的图G'，跳出继续求G'的最小树形图
			break;
		}

		if (i == n)
		{
			for (i = 1; i < n; ++i) if (!flag[i]) sum += mp[pre[i]][i];
			break;
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	freopen("text.in", "r", stdin);
	// 7 15
	// 1 2 9
	// 4 1 3
	// 1 5 5
	// 2 3 3
	// 3 2 7
	// 2 4 9
	// 5 4 4
	// 6 5 3
	// 4 3 8
	// 4 6 5
	// 3 6 9
	// 3 7 6
	// 7 3 4
	// 6 7 4
	// 7 6 8
	int n, m, i, j, w;
	cin >> n >> m;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			mp[i][j] = 1e9;
		}
	}
	for (int k = 0; k < m; ++k)
	{
		cin >> i >> j >> w;
		mp[i-1][j-1] = w;
	}
	cout << min_tree_in_oriented_graph(n, mp) << endl;
	return 0;
}
