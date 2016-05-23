#include <cstdio>

#define MOD 1000000007
typedef long long LL;

LL pow(LL a, LL b)
{
	LL base = a;
	LL r = 1;
	while(b!=0)
	{
		if (b&1) r=r*base%MOD;
		base=base*base%MOD;
		b>>=1;
	}
	return r;
}

LL fuck(int x)
{
	LL ret = 1;
	for (int i = 2; i <= x; ++i)
	{
		ret = ret * i % MOD;
	}
	return ret;
}

LL solve(int n, int m)
{
	return ((fuck(n+m-2) * pow(fuck(n-1), MOD-2)) % MOD) * pow(fuck(m-1), MOD-2) % MOD;
}

int main(int argc, char const *argv[])
{
	int n, m;
	while(~scanf("%d %d", &n, &m))
		if (n == 2 || m == 2)
			printf("1\n");
		else
			printf("%lld\n", solve(n-1, m-1));
	return 0;
}
