#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

typedef long long LL;
using namespace std;
#define maxn 2020

int hp[maxn][maxn], hq[maxn][maxn];
int ip[maxn], iq[maxn];
LL bp[maxn][32], bq[maxn][32];

int main(int argc, char const *argv[])
{
	int T, n;
	char input[maxn];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		int m = (n>>6) + 1;
		int flag = 0, ans = 1;
		for (int i = 0; i < n; ++i) ip[i] = 0, iq[i] = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", input);
			if (flag) continue;
			bool fp = 0, fq = 0;
			for (int j = 0; j < m; ++j) bp[i][j] = 0, bq[i][j] = 0;
			for (int j = 0; j < n; ++j)
				if (input[j] == 'P')
				{
					fp = 1;
					hp[j][ip[j]++] = i;
					bp[i][j>>6] |= (1LL<<(j%64));
				}
				else if (input[j] == 'Q')
				{
					fq = 1;
					hq[j][iq[j]++] = i;
					bq[i][j>>6] |= (1LL<<(j%64));
				}
			if (fp)
			{
				for (int k = 0; k < ip[i]; ++k)
					for (int j = 0; j < m; ++j)
						if ((bp[i][j] & bp[hp[i][k]][j]) != bp[i][j]) flag = 1, ans = 0;
			}
			if (fq)
			{
				for (int k = 0; k < iq[i]; ++k)
					for (int j = 0; j < m; ++j)
						if ((bq[i][j] & bq[hq[i][k]][j]) != bq[i][j]) flag = 1, ans = 0;
			}
			bp[i][i>>6] |= 1LL<<(i%64);
			bq[i][i>>6] |= 1LL<<(i%64);
		}
		if (ans == 1) puts("T");
		else puts("N");
	}
	return 0;
}

