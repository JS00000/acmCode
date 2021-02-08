#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
#define MOD 998244353
#define N 1000010
long inv[N];

int main()
{
	ll n, m;
	scanf("%lld%lld", &n, &m);
    inv[1] = 1;
    for(int i = 2; i <= m; i++)
    {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    ll tmp = 1, val = n + m - 1;
    for(int i = 1; i <= m; i++)
    {
        tmp = tmp % MOD * (val - i + 1) % MOD * inv[i] % MOD;
    }
    printf("%lld\n", tmp);
    return 0;
}
