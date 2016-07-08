#include <cstdio>

using namespace std;

#define MOD 1000000007

long long qp(long long a, long long b)
{
    long long ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

long long fac[10000007];

long long ccc(long long x, long long y)
{
    long long ans = fac[x] * qp(fac[y], MOD - 2) % MOD * qp(fac[x - y], MOD - 2) % MOD;
    //printf("C %lld %lld = %lld\n", x, y, ans);
    return ans;
}

long long exccc(long long a, long long b, long long x, long long y)
{
    if ((y < 0) || (y > x + 1)) return 0;
    if (y == 0) return a;
    if (y == x + 1) return b;
    long long ans = (ccc(x, y) * a % MOD + ccc(x, y - 1) * b % MOD) % MOD;
    //printf("exC %lld %lld = %lld\n", x, y, ans);
    return ans;
}

#define MAX 10000000LL

int main()
{
    long long a, b, x, y, z;
    fac[0] = 1;
    for (long long i = 1; i <= 10000000; i++)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    while (scanf("%lld%lld%lld%lld%lld", &a, &b, &x, &y, &z) == 5)
    {
        long long ans1 = (exccc(a, b, y + 1, z + 1) - exccc(a, b, x, z + 1) + MOD) % MOD;
        printf("%lld\n", ans1);
    }
    return 0;
}
