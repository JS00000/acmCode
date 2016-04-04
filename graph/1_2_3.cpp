// 邻接表
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 10001

using namespace std;


struct EdgeNode
{
	int to;
	int w;
};
vector<EdgeNode> map[MAXN];

bool s[MAXN] = {0} ;
void dfs(int x)
{
	s[x] = 1;
	printf("%d\n", x);
	for (vector<EdgeNode>::iterator i = map[x].begin(); i!=map[x].end() ; ++i)
	{
		if (!s[(*i).to])
		{
			dfs((*i).to);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,m,i,j,w;
	cin >> n >> m;
	EdgeNode e;
	for (int k = 0; k < m; ++k)
	{
		cin >> i >> j >> w;
		e.to = j;
		e.w = w;
		map[i].push_back(e);
	}
	for (int i = 1; i <= n; ++i)
	{
		for (vector<EdgeNode>::iterator k = map[i].begin(); k!=map[i].end(); ++k)
		{
			EdgeNode t = *k;
			cout << i << " " << t.to << " " << t.w << endl;
		}
	}
	dfs(1);
	cin >> n;
	return 0;
}