#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> g[101];
int du[101],n,m;
bool flag;

bool toposort()
{
	memset(du, 0, sizeof(du));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < g[i].size(); ++j)
		{
			du[g[i][j]]++;
		}
	}
	int tot = 0;
	queue<int> Q;
	for (int i = 1; i <= n; ++i)
		if (!du[i]) Q.push(i);
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		tot++;
		for (int j = 0; j < g[x].size(); ++j)
		{
			int t = g[x][j];
			du[t]--;
			if (!du[t])
			{
				Q.push(t);
			}
		}
	}
	if (tot == n) return 1;
	else return 0;
}

int main(int argc, char const *argv[])
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int a,b;
		bool flag;
		for (int i = 0; i < n+1; ++i)
		{
			g[i].clear();
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			flag = true;
			for (int j = 0; j < g[b].size(); ++j)
				if (g[b][j]==a) flag=false;
			if (flag)
				g[b].push_back(a);
		}
		if (toposort())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}
