#include <cstdio>

#define maxK 1000010
#define mod 1000000007LL

typedef long long LL;
LL invi[maxK], ck[maxK];

LL ModPow(LL x, int n) {
    LL ret = 1;
    while (n) {
        if (n & 1) ret = ret * x % mod;
        x = x * x % mod; n >>= 1;
    }
    return ret;
}

//@ Main Function
int main() {
    for (int i = 1; i < maxK; i++) invi[i] = ModPow(i, mod - 2);
    int _case;
    LL n, m, k;
    scanf("%d", &_case);
    for (int __case = 1; _case; _case--, __case++) {
        scanf("%lld%lld%lld", &n, &m, &k);
        LL cmk = 1;
        for (int i = 1; i <= k; i++)
            cmk = cmk * (m - i + 1) % mod * invi[i] % mod;

        ck[0] = 1;
        for (int i = 1; i <= k; i++)
            ck[i] = ck[i - 1] * (k - i + 1) % mod * invi[i] % mod;

        LL ans = 0;
        for (int i = k, sgn = 1; i >= 1; i--, sgn = -sgn)
            ans = (ans + sgn * (i * ModPow(i - 1, n - 1) % mod * ck[i] % mod)) % mod;
        ans = (ans + mod) % mod * cmk % mod;

        printf("Case #%d: %lld\n", __case, ans);
    }
    return 0;
}