#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char a[501][501];
int f[501][501];
int n,m,k;

int findPos(int &pi, int &pj)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (f[i][j]==1)
			{
				pi = i;
				pj = j;
				return 0;
			}
		}
	}
	
	return 0;
}

int main(int argc, char const *argv[])
{
	cin >> n >> m >> k;
	memset(f,0,sizeof(f));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j]=='.')
			{
				if (i>0&&a[i-1][j]=='.')
				{
					f[i][j]++;
					f[i-1][j]++;
				}
				if (i<n-1&&a[i+1][j]=='.')
				{
					f[i][j]++;
					f[i+1][j]++;
				}
				if (j>0&&a[i][j-1]=='.')
				{
					f[i][j]++;
					f[i][j-1]++;
				}
				if (j<m-1&&a[i][j+1]=='.')
				{
					f[i][j]++;
					f[i][j+1]++;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			f[i][j]=int(f[i][j]/2);
		}
	}

	int i=0,j=0;
	bool flag=false;
	while(k)
	{
		if (!flag)
		{
			findPos(i,j);
		}
		a[i][j]='X';
		f[i][j]=0;
		k--;
		flag = false;
		if (i>0&&a[i-1][j]=='.')
		{
			f[i-1][j]--;
			if (f[i-1][j]==1)
			{
				i--;
				flag=true;
				continue;
			}
		}
		if (i<n-1&&a[i+1][j]=='.')
		{
			f[i+1][j]--;
			if (f[i+1][j]==1)
			{
				i++;
				flag=true;
				continue;
			}
		}
		if (j>0&&a[i][j-1]=='.')
		{
			f[i][j-1]--;
			if (f[i][j-1]==1)
			{
				j--;
				flag=true;
				continue;
			}
		}
		if (j<m-1&&a[i][j+1]=='.')
		{
			f[i][j+1]--;
			if (f[i][j+1]==1)
			{
				j++;
				flag=true;
				continue;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}