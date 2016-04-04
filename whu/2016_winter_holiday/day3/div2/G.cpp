#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int n,m,k,d=0;
char mmap[1001][1001];
int f[1001][1001];
bool flag[1001][1001];
bool row[1001][1001];
bool column[1001][1001];
int ans[300000];

struct pos
{
	int x;
	int y;
};

void calc(int x, int y)
{
	if (row[x-1][y])
	{
		ans[d]++;
		row[x-1][y] = false;
	}
	if (row[x][y])
	{
		ans[d]++;
		row[x][y] = false;
	}
	if (column[x][y])
	{
		ans[d]++;
		column[x][y] = false;
	}
	if (column[x][y+1])
	{
		ans[d]++;
		column[x][y+1] = false;
	}
}

int bfs(int x, int y)
{
	if (!flag[x][y])
	{
		return ans[f[x][y]];
	}
	d++;	
	pos temp;
	queue<pos> location;
	temp.x = x;
	temp.y = y;
	location.push(temp);
	flag[x][y] = false;
	f[x][y] = d;
	calc(x,y);
	while(!location.empty())
	{
		int px,py,tx,ty;
		px = location.front().x;
		py = location.front().y;
		location.pop();
		for (int i = 0; i < 4; ++i)
		{
			tx = px + dx[i];
			ty = py + dy[i];
			if (tx>0&&tx<n-1&&ty>0&&ty<m-1&&flag[tx][ty]&&mmap[tx][ty]=='.')
			{
				flag[tx][ty] = false;
				pos temp2;
				temp2.x = tx;
				temp2.y = ty;
				location.push(temp2);
				f[tx][ty] = d;
				calc(tx,ty);
			}
		}
	}
	return ans[d];
}

int main(int argc, char const *argv[])
{
	cin >> n >> m >> k;
	memset(row,false,sizeof(row));
	memset(column,false,sizeof(column));
	memset(flag,true,sizeof(flag));
	memset(ans,0,sizeof(ans));
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",mmap[i]);
	}
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 1; j < m-1; ++j)
		{
			if (mmap[i][j]!=mmap[i+1][j])
			{
				row[i][j] = true;
			}
		}
	}
	for (int i = 1; i < n-1; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if (mmap[i][j]!=mmap[i][j-1])
			{
				column[i][j] = true;
			}
		}
	}
	for (int i = 0; i < k; ++i)
	{
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		cout << bfs(x,y) << endl;
	}
	return 0;
}