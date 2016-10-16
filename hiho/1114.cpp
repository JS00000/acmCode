#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	int n, ai;
	int f[2];
	int a[100007];
	int flag[100007];
	int flag2[100007];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		f[0] = f[1] = 0;
		scanf("%d", a);
		if (a[0] == 0 || a[0] == 2)
		{
			flag[0] = flag[1] = a[0]/2;
			f[a[0]/2] += 2;
			for (int i = 1; i < n - 1; ++i)
			{
				scanf("%d", &ai);
				flag[i+1] = ai - flag[i] - flag[i-1];
				f[flag[i+1]]++;
			}
			scanf("%d", &ai);
		}
		else
		{
			bool p = 1, p2 = 1;
			flag[0] = 0;
			flag[1] = 1;
			for (int i = 1; i < n - 1; ++i)
			{
				scanf("%d", a+i);
				flag[i+1] = a[i] - flag[i] - flag[i-1];
				if (flag[i+1] > 1 || flag[i+1] < 0)
				{
					p = 0;
				}
			}
			scanf("%d", a+n-1);
			if (a[n-1] != flag[n-2] + flag[n-1])
			{
				p = 0;
			}

			flag2[0] = 1;
			flag2[1] = 0;
			for (int i = 1; i < n - 1; ++i)
			{
				flag2[i+1] = a[i] - flag2[i] - flag2[i-1];
				if (flag2[i+1] > 1 || flag2[i+1] < 0)
				{
					p2 = 0;
				}
			}
			if (a[n-1] != flag2[n-2] + flag2[n-1])
			{
				p2 = 0;
			}

			if (p && p2)
			{
				for (int i = 0; i < n; ++i)
				{
					if (flag[i] != flag2[i]) flag[i] = -1;
					else f[flag[i]]++;
				}
			}
			else if (!p)
			{
				for (int i = 0; i < n; ++i)
				{
					flag[i] = flag2[i];
					f[flag[i]]++;
				}
			}
			else if (!p2)
			{
				for (int i = 0; i < n; ++i)
				{
					f[flag[i]]++;
				}
			}
		}
		printf("%d", f[1]);
		for (int i = 0; i < n; ++i)
		{
			if (flag[i] == 1)
			{
				printf(" %d", i + 1);
			}
		}
		printf("\n");
		printf("%d", f[0]);
		for (int i = 0; i < n; ++i)
		{
			if (flag[i] == 0)
			{
				printf(" %d", i + 1);
			}
		}
		printf("\n");
	}
	return 0;
}