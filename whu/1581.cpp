#include <cstdio>
#include <cstring>

int s[10][100][1000];
bool p[10][100][1000] = {0};

int main(int argc, char const *argv[])
{
	int n,k,m;
	while(scanf("%d%d%d", &n, &k, &m) == 3)
	{
		int tot = n*n*n*k*k*k, v;
		int i = 0, j = 0, k = 0, x1,x2,y1,y2,z1,z2;
		for (int z = 0; z <tot ; ++z)
		{
			scanf("%d", &v);
			s[i][j][k] = v;
			k++;
			if (k==n*k*k)
			{
				j++;
				k=0;
			}
			if (j==n*k)
			{
				i++;
				j=0;
			}
		}
		memset(p,0,sizeof(p));
		long long sum = 0, maxans = -10000000000000000;
		for (int z = 0; z < m; ++z)
		{
			scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
			x1--;x2--;y1--;y2--;z1--;z2--;
			for (int i = x1; i <= x2; ++i)
			{
				for (int j = y1; j <= y2; ++j)
				{
					for (int k = z1; k <= z2; ++k)
					{
						if (!p[i][j][k])
						{
							p[i][j][k] = 1;
							sum += s[i][j][k];
						}
					}
				}
			}
			if (sum > maxans)
			{
				maxans = sum;
			}
		}
		printf("%lld\n", maxans);
	}
	return 0;
}