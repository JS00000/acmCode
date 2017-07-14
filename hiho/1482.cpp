#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long

const int maxn = 100007;
const LL mod = 1e9+7;

using namespace std;

LL f[maxn];

int main()
{
    f[0] = 1;
    f[1] = 2;
    f[2] = 4;
    f[3] = 7;
    int n;
    scanf("%d", &n);
    for (int i = 4; i <= n; ++i)
        f[i] = (f[i-1]*2%mod - f[i-4] + mod) % mod;
    LL ans = f[n];
    for (int i = 0; i < n; ++i)
        ans = (ans + f[i]*f[n-i-1]%mod) % mod;
    printf("%lld\n", ans);
    return 0;
}
