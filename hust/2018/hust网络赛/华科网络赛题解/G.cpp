#include <bits/stdc++.h>
using namespace std;
#define zeros(a,n) memset(a,0,(n)*sizeof(a[0]))
typedef long long LL;
typedef unsigned long long ULL;
const LL modn = 1e9+7;

struct point
{
    LL x, y;
    point operator +(const point &rhs) const
    {
        return (point){x + rhs.x, y + rhs.y};
    }
    point operator -(const point &rhs) const
    {
        return (point){x - rhs.x, y - rhs.y};
    }
    point operator *(const LL &rhs) const
    {
        return (point){x * rhs, y * rhs};
    }
    LL operator *(const point &rhs) const
    {
        return x * rhs.x + y * rhs.y;
    }
    bool operator==(const point &rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
};

LL quickpow(LL a, LL n, LL p)
{
    LL ans = 1;
    while(n) {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}
LL sqr(LL x)
{
    return x * x;
}

LL xmult(const point &lhs, const point &rhs)
{
    return lhs.x * rhs.y - rhs.x * lhs.y;
}

bool isorthocenter(point a, point b, point c, point o)
{
    return (b-a)*(c-o)==0 && (c-b)*(a-o)==0 && (a-c)*(b-o)==0;
}
bool isbarycenter(point a, point b, point c, point o)
{
    return a + b + c == o*3;
}
bool isexcenter(point a, point b, point c, point o)
{
    LL la = (o-a)*(o-a);
    LL lb = (o-b)*(o-b);
    LL lc = (o-c)*(o-c);
    return la == lb && lb == lc;
}
bool isincenter(point a, point b, point c, point o)
{
    LL ta = xmult(b-a, o-a);
    LL tb = xmult(c-b, o-b);
    LL tc = xmult(a-c, o-c);
    if(ta < 0 || tb < 0 || tc < 0) return false;
    LL la = sqr(ta%modn) % modn * quickpow((b-a)*(b-a)%modn, modn-2, modn) % modn;
    LL lb = sqr(tb%modn) % modn * quickpow((c-b)*(c-b)%modn, modn-2, modn) % modn;
    LL lc = sqr(tc%modn) % modn * quickpow((a-c)*(a-c)%modn, modn-2, modn) % modn;
    return la == lb && lb == lc;
}

int main()
{
    point a, b, c, o;
    scanf("%lld %lld", &a.x, &a.y);
    scanf("%lld %lld", &b.x, &b.y);
    scanf("%lld %lld", &c.x, &c.y);
    scanf("%lld %lld", &o.x, &o.y);
    if(xmult(b-a, c-a) < 0) swap(b, c);
    bool flag = false;
    flag |= isorthocenter(a, b, c, o);
    flag |= isbarycenter(a, b, c, o);
    flag |= isexcenter(a, b, c, o);
    flag |= isincenter(a, b, c, o);
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}

