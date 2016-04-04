#include <cstdio>
#include <iostream>
using namespace std;
int n,m,k;
char g[600][600];
int v[600][600];
void dfs(int x, int y)
{
	if (x<0||x>=n||y<0||y>=m||!k) return;
	if (g[x][y]=='.'&&!v[x][y])
	{
		v[x][y] = 1;
		dfs(x+1,y);
		dfs(x,y+1);
		dfs(x-1,y);
		dfs(x,y-1);
		if (k)
		{
			g[x][y] = 'X';
			k--;
		}
	}
}
int main(int argc, char const *argv[])
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",g[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		if (!k)
		{
			break;
		}
		for (int j = 0; j < m; ++j)
		{
			dfs(i,j);
			if (!k)
			{
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%c", g[i][j]);
		}
		printf("\n");
	}
	return 0;
}