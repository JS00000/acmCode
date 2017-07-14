// 扫雷 double
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 300
using namespace std;

int check_is_contain(int p1[], int p2[], int ip1, int ip2, int p3[])
{
	sort(p1, p1+ip1);
	sort(p2, p2+ip2);	
	int i1 = 0, i2 = 0, i3 = 0;
	while(i1 < ip1 && i2 < ip2)
		if (p1[i1] == p2[i2]) i1++, i2++;
		else p3[i3++] = p1[i1++];
	if (i2 != ip2) return 0;
	while(i1 < ip1) p3[i3++] = p1[i1++];
	return i3;
}

void solve(int mp[][maxn], int n, int m)
{
	int flag[maxn][maxn];
	int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			flag[i][j] = 3;
	for (int i = 0; i <= n+1; ++i) mp[i][0] = mp[i][m+1] = -2;
	for (int i = 0; i <= m+1; ++i) mp[0][i] = mp[n+1][i] = -2;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (mp[i][j] == 0)
				for (int k = 0; k < 8; ++k) if (mp[i+di[k]][j+dj[k]] == -1) flag[i+di[k]][j+dj[k]] &= 2;
			if (mp[i][j] > 0)
			{
				int uc = 0;
				for (int k = 0; k < 8; ++k) if (mp[i+di[k]][j+dj[k]] == -1) uc++;
				if (uc == mp[i][j])
					for (int k = 0; k < 8; ++k)
						if (mp[i+di[k]][j+dj[k]] == -1) flag[i+di[k]][j+dj[k]] &= 1;
			}
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int ai = -2; ai <= 2; ++ai)
				for (int aj = 0; aj <= 2; ++aj)
					if ((ai || aj) && 0 < i+ai && i+ai<=n && 0 < j+aj && j+aj<=m && mp[i][j] >= 0 && mp[i+ai][j+aj] >= 0)
					{
						int p1[8], p2[8], ip1 = 0, ip2 = 0, p3[8];
						for (int k = 0; k < 8; ++k)
						{
							if (mp[i+di[k]][j+dj[k]] == -1) p1[ip1++] = (i+di[k]-1)*m+j+dj[k];
							if (mp[i+ai+di[k]][j+aj+dj[k]] == -1) p2[ip2++] = (i+ai+di[k]-1)*m+j+aj+dj[k];
						}
						if (ip1 - ip2 == mp[i][j] - mp[i+ai][j+aj] && ip1 != ip2)
						{
							int conn;
							if (ip1 > ip2) conn = check_is_contain(p1, p2, ip1, ip2, p3);
							else conn = check_is_contain(p2, p1, ip2, ip1, p3);
							if (conn) for (int ip3 = 0; ip3 < conn; ++ip3) flag[(p3[ip3]-1)/m+1][(p3[ip3]-1)%m+1] &= 1;
						}
					}
	int count1 = 0, count2 = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (flag[i][j] == 1) count1++;
			else if (flag[i][j] == 2) count2++;
	printf("%d %d\n", count1, count2);
}

int main()
{
	int T, n, m;
	int mp[maxn][maxn];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%d", &mp[i][j]);
		solve(mp, n, m);
	}
	return 0;
}
