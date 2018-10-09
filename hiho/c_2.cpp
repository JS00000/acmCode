#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

ll qpow(ll a,ll b)
{
    ll ans=1;a%=mod;
    for(int i=b;i;i>>=1,a=a*a%mod)
        if(i&1)ans=ans*a%mod;
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n, a, b, c, d;
        scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
        printf("%lld %lld %lld %lld %lld is output\n", n, a, b, c, d);
        ll ans = 0;
        if (n & 1) {
            if (a < 0) ans -= qpow(-a, n);
            else ans += qpow(a, n);
            if (b < 0) ans -= qpow(-b, n);
            else ans += qpow(b, n);
            if (c < 0) ans -= qpow(-c, n);
            else ans += qpow(c, n);
            if (d < 0) ans -= qpow(-d, n);
            else ans += qpow(d, n);
        } else {
            if (a < 0) ans += qpow(-a, n);
            else ans += qpow(a, n);
            if (b < 0) ans += qpow(-b, n);
            else ans += qpow(b, n);
            if (c < 0) ans += qpow(-c, n);
            else ans += qpow(c, n);
            if (d < 0) ans += qpow(-d, n);
            else ans += qpow(d, n);
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}
