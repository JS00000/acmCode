#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 8;
const ll MOD = 1e9 + 7;

int n, m;

struct $matrix
{
	ll con[MAXN][MAXN];
	$matrix()
	{
		for(int i = 0; i < MAXN; i++)
			for(int j = 0; j < MAXN; j++)
				con[i][j] = 0;
	}
};

struct $matrix mult( struct $matrix& a, struct $matrix& b )
{
	struct $matrix ans;
	for(int i = 1; i <= 6; i++)
		for(int j = 1; j <= 6; j++)
			if(a.con[i][j])
				for(int k = 1; k <= 6; k++)
					ans.con[i][k] += a.con[i][j] * b.con[j][k];
	return ans;
}

struct $matrix m_pow( struct $matrix a, int b )
{
	struct $matrix ans;
	for(int i = 1; i <= 6; i++)
		ans.con[i][i] = 1;
	while(b)
	{
		if(b & 1)
			ans = mult( ans, a );
		a = mult( a, a );
		b /= 2;
	}
	return ans;
}

ll q_pow( ll a, ll b, ll c )
{
	ll ans = 1;
	while(b)
	{
		if(b & 1)
		{
			ans = (ans * a) % c;
		}
		b /= 2;
		a = (a*a) % c;
	}
	return ans;
}

int main()
{
//没有找到judge，感觉应该没问题。请各位指教，多谢！
	struct $matrix ini;
	for(int i = 1; i <= 6; i++)
		ini.con[1][i] = 1;
	struct $matrix con;
	for(int i = 1; i <= 6; i++)
		for(int j = 1; j <= 6; j++)
			con.con[i][j] = 1;

	while(scanf( "%d%d", &n, &m ) == 2)
	{
		int a, b;
		for(int i = 1; i <= m; i++)
		{
			scanf( "%d%d", &a, &b );
			con.con[a][b] = con.con[b][a] = 0;
		}

		ini = mult( ini, m_pow( con, n - 1 ) );
		long long ans = 0;
		for(int i = 1; i <= 6; i++)
		{
			ans += ini.con[1][i];
		}
		ll times = q_pow( 4, n, MOD );
		ans = (ans*times) % MOD;
		printf( "%lld\n", ans );
	}

	return 0;
}