#include <iostream>
#include <cstdio>
#include <cmath>

#define mod 1000000007

using namespace std;

long long c[1010][1010];

long pow(long a, long b, long n)
{
	long base = a;
	long r = 1;
	while(b!=0)
	{
		if (b&1) r=r*base%n;
		base=base*base%n;
		b>>=1;
	}
	return r;
}

void calc(int l, int m)
{
	for (int i = 0; i <= l; ++i)
	{
		c[i][0] = 1;
		c[i][i] = 1;
	}
	for (int i = 2; i <= l; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
}

int T,n,k,m;
long long ans;
int main(int argc, char const *argv[])
{
	/* code */
	calc(1002,mod);
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		if (k<7)
		{
			cout << "0\n";
			continue;
		}
		ans = 0;
		for (int i = 0; i < n/2; ++i)
		{
			m = i*2+1;
			ans = (ans + (c[n-1][m-1]*pow(k-1,n-m,mod))%mod)%mod;
			ans = (ans + ((c[n-1][m]*pow(k-1,n-m-1,mod)%mod)*(k-2))%mod)%mod;
		}
		if (n%2==1)
		{
			ans = (ans+1)%mod;
		}
		cout << ans << endl;
	}
	return 0;
}
