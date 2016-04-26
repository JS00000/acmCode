// 1578
#include <cstdio>
#include <cstring>
#include <algorithm>

bool s[32770];

int main(int argc, char const *argv[])
{
	int n,m;
	while(~scanf("%d%d", &n, &m))
	{
		int x,max = 0,last = 0;
		memset(s,0,m*sizeof(bool)+10);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			s[x] = 1;
		}
		int j = 0;
		while(!s[j]) j++;
		last = -j;
		for (int i = 0; i < m; ++i)
		{
			if (s[i])
			{
				if (i - last > max)
					max = i - last;
				last = i;
			}
		}
		if ((m - last) * 2 > max)
			max = (m - last) * 2;
		printf("%.2lf\n", double(max)/2);
	}
	return 0;
}