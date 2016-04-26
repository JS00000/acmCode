// 1575
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>

#define MAPSIZE 101
#define MOD 1000000007
using namespace std;
typedef long long LL;


int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

int n,m,tot = 0;
string oriStr;
bool s[MAPSIZE][MAPSIZE], p[MAPSIZE][MAPSIZE];

struct pos
{
	int x,y;
};

void bfs(int x, int y)
{
	p[x][y] = 1;
	queue<pos> q;
	pos temp;
	temp.x = x;
	temp.y = y;
	q.push(temp);
	int sum = 1;
	while(!q.empty())
	{
		for (int i = 0; i < 4; ++i)
		{
			temp.x = q.front().x + dx[i];
			temp.y = q.front().y + dy[i];
			if (temp.x >= 0 && temp.x < n && temp.y >= 0 && temp.y < m && s[temp.x][temp.y] && !p[temp.x][temp.y])
			{
				sum++;
				p[temp.x][temp.y] = 1;
				q.push(temp);
			}
		}
		q.pop();
	}
	tot ++;
}


LL pow(LL a, LL b, LL n)
{
	LL base = a;
	LL r = 1;
	while(b!=0)
	{
		if (b&1) r=r*base%n;
		base=base*base%n;
		b>>=1;
	}
	return r;
}


int main(int argc, char const *argv[])
{
	// freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--)
	{
		tot = 0;
		cin >> n >> m;
		memset(p, 0, sizeof(p));
		memset(s, 0, sizeof(s));
		for (int i = 0; i < n; ++i)
		{
			cin >> oriStr;
			for (int j = 0; j < m; ++j)
				if (oriStr[j] == 'Y') s[i][j] = 1;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (s[i][j] && !p[i][j]) bfs(i,j);
		LL ret = pow(2,tot-1, MOD);
		printf("%llu\n", ret);
	}
	return 0;
}
