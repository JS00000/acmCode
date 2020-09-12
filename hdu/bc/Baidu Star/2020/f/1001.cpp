#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
const long long mod = 998244353;
using namespace std;

long long gcd(long long a, long long b)
{
    return b==0?a:gcd(b, a%b);
}

long long pow_mod(long long a,long long b){
    long long ans = 1 , tmp = a;
    while(b) {
        if (b&1) ans = ans * tmp % mod;
        b>>=1 , tmp = tmp * tmp % mod;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        long long m, p, q;
        scanf("%lld%lld%lld", &m, &p, &q);
        long long fz = ((100 * m * p - 100 * m * q + p * q) % mod + mod) % mod;
        long long fm = 100 * p % mod;
        long long g = gcd(fz, fm);
        fz /= g;
        fm /= g;
        printf("%lld\n", fz * pow_mod(fm, mod-2) % mod);
    }
    return 0;
}
