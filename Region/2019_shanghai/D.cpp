#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL mod = 1000000007;

struct node
{
    LL eq, len, vl, sum, mul;
    LL v[16];
    node() {
        eq = 1;
        len = 0;
        vl = 0;
        sum = 0;
        mul = 1;
    };
    node(LL _eq) {
        eq = _eq;
        len = 1;
        sum = _eq;
        mul = _eq;
        v[0] = _eq;
        vl = 1;
    }
};


LL pow_mod(LL a,LL b)
{
    LL ans = 1;
    a%=mod;
    LL temp = a;
    while( b )
    {
        if ( b & 1 ) ans = ( temp * ans )% mod;
        temp = ( temp * temp )% mod;
        b>>=1;
    }
    return ans;
}

node q[1000000];
LL f[3001];

int main()
{
    freopen("out2.txt", "w", stdout);
    int iq = 0;
    for (int i = 2; i <= 3000; i++) {
        q[iq++] = node(i);
        int j = 0;
        while (j < iq) {
            node now = q[j];
            if (now.eq * i <= 60000) {
                q[iq].eq = now.eq * i;
                q[iq].len = now.mul * i - now.sum - i + now.vl + 1;
                if (q[iq].len > 3000) {
                    j++;
                    continue;
                }
                q[iq].sum = now.sum + i;
                q[iq].mul = now.mul * i;
                for (int k = 0; k < now.vl; k++) {
                    q[iq].v[k] = now.v[k];
                }
                q[iq].v[now.vl] = i;
                q[iq].vl = now.vl+1;
                LL ans = 1;
                LL last = -1, cc = 1, tt = q[iq].len;
                for (int k = 0; k < q[iq].vl; k++) {
                    ans = ans * tt % mod;
                    tt--;
                    if (q[iq].v[k] == last) {
                        cc++;
                        ans = ans * pow_mod(cc, mod-2) % mod;
                        // ans = ans / cc;
                    } else {
                        last = q[iq].v[k];
                        cc = 1;
                    }
                }
                if (q[iq].len > 1) f[q[iq].len] += ans;
                iq++;
            }
            j++;
        }
    }
    for (int i = 0; i <= 3000; i++) {
        printf("%lld,", f[i]);
    }
    // int T, n;
    // scanf("%d", &T);
    // while (T--) {
    //     scanf("%d", &n);
    //     printf("%lld\n", f[n]);
    // }
    return 0;
}
