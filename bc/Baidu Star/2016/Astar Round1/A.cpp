#include <cstdio>
#include <cstring>
#define NUM 9973

using namespace std;

int pow_fast(int a)
{
	int base = a;
	int r = 1;
	int b = 9971;
	while(b!=0)
	{
		if (b&1) r=r*base%9973;
		base=base*base%9973;
		b>>=1;
	}
	return r;
}

int n, a, b, i, rev;
char str[100007];
int f[100007];

int main()
{
	while(~scanf("%d", &n))
	{
		getchar();
		gets(str);
		f[0] = 1;
		int len = strlen(str);
		for (i = 1; i <= len; ++i)
			f[i] = f[i-1] * (str[i-1] - 28) % NUM;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &a, &b);
			rev = pow_fast(f[a-1]);
			printf("%d\n", f[b] * rev % NUM);
		}
	}
	return 0;
}
