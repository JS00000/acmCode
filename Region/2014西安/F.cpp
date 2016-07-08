#include <cstdio>

#define MOD 1000000007

using namespace std;

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
LL n, m, k, ans, temp;
LL c[1000007];

void calcC(int n)
{
	c[0] = 1;
	for (int i = 1; i <= k; i++)
	{
		c[i] = c[i-1] * (n-i+1) % MOD * pow(i, MOD-2) % MOD;
	}
}


int main(int argc, char const *argv[])
{
	int t, kase = 1;
	scanf("%d", &t);
	while(kase <= t)
	{
		scanf("%I64d%I64d%I64d", &n, &m, &k);
		calcC(m);
		temp = c[k];
		calcC(k);
		ans = 0;
		for (int i = k; i > 1; i--)
			ans = (ans + pow(-1, k-i) * c[i] * i % MOD * pow(i-1, n-1) % MOD + MOD)  % MOD ;
		printf("Case #%d: %I64d\n", kase, ans * temp % MOD );
		kase++;
	}
	return 0;
}
