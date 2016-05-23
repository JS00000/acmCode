#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>

#define maxn 1007
#define maxm 2014

using namespace std;

int n, m;
struct node
{
	int to, next;
}edge[maxm];
int head[maxn];

void creatGraph()
{
	int a, b;
	scanf("%d", &n);
	m = n - 1;
	memset(head, 0, (n+1)*sizeof(int));
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d", &a, &b);
		edge[i*2-1].to = b;
		edge[i*2-1].next = head[a];
		head[a] = i*2-1;
		edge[i*2].to = a;
		edge[i*2].next = head[b];
		head[b] = i*2;
	}
}


int p[maxn];
bool select[maxn];
int newpos[maxn];
int now;
void dfs(int x)
{
	newpos[now++] = x;
	for (int k = head[x]; k != 0; k = edge[k].next)
	{
		if (!select[edge[k].to])
		{
			select[edge[k].to] = true;
			p[edge[k].to] = x;
			dfs(edge[k].to);
		}
	}
}

int greedy_min_governed()
{
	bool s[maxn] = {0};
	bool set[maxn] = {0};
	int ans = 0;
	for (int i = n-1; i >= 0; --i)
	{
		int t = newpos[i];
		if (!s[t])
		{
			if (!set[p[t]])
			{
				set[p[t]] = true;
				ans++;
			}
			s[t] = true;
			s[p[t]] = true;
			s[p[p[t]]] = true;
		}
	}
	// for (int i = 1; i <= n; ++i)
		// if (set[i]) printf("%d ", i);
	// printf("\n");
	return ans;
}

int greedy_min_cover()
{
	bool s[maxn] = {0};
	bool set[maxn] = {0};
	memset(s, 0, sizeof(s));
	memset(set, 0, sizeof(set));
	int ans = 0;
	for (int i = n-1; i >= 0; --i)
	{
		int t = newpos[i];
		if (!s[t] && !s[p[t]])
		{
			set[p[t]] = true;
			ans++;
			s[t] = true;
			s[p[t]] = true;
		}
	}
	// for (int i = 1; i <= n; ++i)
	// 	if (set[i]) printf("%d ", i);
	// printf("\n");
	return ans;
}

int greedy_max_indepen()
{
	bool s[maxn] = {0};
	bool set[maxn] = {0};
	int ans = 0;
	for (int i = n-1; i >= 0; --i)
	{
		int t = newpos[i];
		if (!s[t])
		{
			set[t] = true;
			ans++;
			s[t] = true;
			s[p[t]] = true;
		}
	}
	// for (int i = 1; i <= n; ++i)
	// 	if (set[i]) printf("%d ", i);
	// printf("\n");
	return ans;
}

int dp[maxn][3];

void dp_min_governed(int u, int p)
{
	dp[u][2] = 0;
	dp[u][0] = 1;
	bool s = false;
	int sum = 0, to, inc = INT_MAX;
	for (int k = head[u]; k != 0; k = edge[k].next)
	{
		to = edge[k].to;
		if (to == p) continue;
		dp_min_governed(to, u);
		dp[u][0] += min(min(dp[to][0], dp[to][1]), dp[to][2]);
		if (dp[to][0] <= dp[to][1])
		{
			sum += dp[to][0];
			s = true;
		}
		else
		{
			sum += dp[to][1];
			inc = min(inc, dp[to][0]-dp[to][1]);
		}
		if (dp[to][1] != INT_MAX && dp[u][2] != INT_MAX) dp[u][2] += dp[to][1];
		else dp[u][2] = INT_MAX;
	}
	if (inc == INT_MAX && !s) dp[u][1] = INT_MAX;
	else
	{
		dp[u][1] = sum;
		if (!s) dp[u][1] += inc;
	}
}

void dp_min_cover(int u, int p)
{
	dp[u][0] = 1;
	dp[u][1] = 0;
	int to;
	for (int k = head[u]; k != 0; k = edge[k].next)
	{
		to = edge[k].to;
		if (to == p) continue;
		dp_min_cover(to, u);
		dp[u][0] += min(dp[to][0], dp[to][1]);
		dp[u][1] += dp[to][0];
	}
}

void dp_max_indepen(int u, int p)
{
	dp[u][0] = 1;
	dp[u][1] = 0;
	int to;
	for (int k = head[u]; k != 0; k = edge[k].next)
	{
		to = edge[k].to;
		if (to == p) continue;
		dp_max_indepen(to, u);
		dp[u][0] += dp[to][1];
		dp[u][1] += max(dp[to][0], dp[to][1]);
	}
}

int main(int argc, char const *argv[])
{
	freopen("tree.in", "r", stdin);
	creatGraph();
	memset(select, 0, (n+1)*sizeof(bool));
	now = 0;
	select[2] = true;
	p[2] = 2;
	dfs(2);

	printf("greedy_min_governed			%d\n", greedy_min_governed());
	printf("greedy_max_indepen			%d\n", greedy_max_indepen());

	memset(select, 0, (n+1)*sizeof(bool));
	now = 0;
	p[2] = 2;
	dfs(2);
	printf("greedy_min_cover			%d\n", greedy_min_cover());


	printf("\n");

	dp_min_governed(1, 1);
	printf("dp_min_governed				%d\n", min(min(dp[1][0], dp[1][1]), dp[1][2]) );

	dp_max_indepen(1, 1);
	printf("dp_max_indepen				%d\n", max(dp[1][0], dp[1][1]));

	dp_min_cover(1, 1);
	printf("dp_min_cover				%d\n", min(dp[1][0], dp[1][1]));

	printf("\n");
	printf("______________________________________Test______________________________________\n\n");

	memset(select, 0, (n+1)*sizeof(bool));
	memset(newpos, 0, sizeof(newpos));
	now = 0;
	select[2] = true;
	p[2] = 2;
	dfs(2);
	for (int j = n-1; j >= 0; --j) printf("%3d", newpos[j]);
	printf("\n");
	for (int j = n-1; j >= 0; --j) printf("%3d", p[newpos[j]]);
	printf("\n");
	printf("%d\n", greedy_min_cover());

	memset(select, 0, (n+1)*sizeof(bool));
	memset(newpos, 0, sizeof(newpos));
	now = 0;
	// select[2] = true;
	p[2] = 2;
	dfs(2);
	for (int j = n-1; j >= 0; --j) printf("%3d", newpos[j]);
	printf("\n");
	for (int j = n-1; j >= 0; --j) printf("%3d", p[newpos[j]]);
	printf("\n");
	printf("%d\n", greedy_min_cover());

	printf("\n");

	return 0;
}