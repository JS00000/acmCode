#include <cmath>
#include <cstdio>

#define llu unsigned long long

llu gcd(llu a, llu b)
{
    return b ? gcd(b, a%b) : a;
}

int main()
{
    llu n, m;
    scanf("%lld%lld", &n, &m);
    llu A = 2, B = 2, C, ma;
    ma = (llu)(sqrt(n));
    for (int i = 2; i <= ma; i++) if (n % i == 0) A+=2;
    if (n == ma*ma) A-=1;

    ma = (llu)(sqrt(m));
    for (int i = 2; i <= ma; i++) if (m % i == 0) B+=2;
    if (m == ma*ma) B-=1;

    llu g = gcd(n, m);
    if (g == 1) C = 1;
    else
    {
        C = 2;
        ma = (llu)(sqrt(g));
        for (int i = 2; i <= ma; i++) if (g % i == 0) C+=2;
        if (g == ma*ma) C-=1;
    }

    printf("%lld %lld\n", A*B/gcd(A*B, C), C/gcd(A*B, C));
    return 0;
}
