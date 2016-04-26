// unfinished
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 10010
#define MAXD 15

using namespace std;

bool p[MAXN][MAXD];
int f[MAXN][MAXD][2];
int d[MAXN];
int N, k, Q;

// x < N
int deep(int x)
{
	if (x == 0) return 0;
	int deep = 1, num = k-1;
	while(num < x)
	{
		deep++;
		num += num*k;
	}
	return deep;
}

bool isComplete(int ret, int de)
{
	if (ret == 0)
	{
		ret = k-1;
		de--;
	}
	for (int j = 0; j < de; ++j)
	{
		ret = ret * k;
	}
	if (ret + k - 1 < N) return true;
	return false;
}

int calcSelf(int ret, int de, int &ans0, int &ans1)
{
	int num;
	if (ret == 0) num = k - 2;
	else num = k - 1;
	for (int i = 1; i < de; ++i)
	{
		num += num*k;
	}
	
	return 0;
}

int main(int argc, char const *argv[])
{
	while(scanf("%d%d%d", &N, &k, &Q) == 3)	
	{
		for (int i = 0; i < N; ++i)
		{
			d[i] = deep(i);
		}
		int maxDeep = d[N-1];
		for (int i = 0; i < N; ++i)
		{
			f[i][0][0] = i;
			f[i][0][1] = 0;
		}
		for (int j = 1; j <= maxDeep; ++j)
		{
			for (int i = 0; i < N; ++i)
			{
				if ((p[i][j] = isComplete(i, j)))
				{
					printf("%d %d YES\n", i, j);
					calcSelf(i, j, f[i][j][0], f[i][j][1]);
				}
				else
				{
					printf("%d %d NO \n", i, j);
					calcSelf(i, j, f[i][j][0], f[i][j][1]);
				}
			}
		}
	}
	return 0;
}