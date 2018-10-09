#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL mod = 1e9+7;
map<int, LL> m;

//分解质因数
//k为1或-1
void fun(int n, int k)
{
    for (int i = 2; i <= sqrt(n * 1.0); i++) {
        while (n % i == 0) {
            n /= i;
            m[i] += k;
        }
    }
    if (n > 1) {
        m[n] += k;
    }
}

//大数快速幂取模
LL quick_pow(LL a, LL b)
{
    LL ret = 1;
    while (b) {
        if (b & 1) {
            ret *= a;
            ret %= mod;
        }
        b >>= 1;
        a *= a;
        a %= mod;
    }
    return ret;
}

//求组合数
LL C(LL a, LL b)
{
    if (a < b || a < 0 || b < 0)
        return 0;
    m.clear();
    LL ret = 1;
    b = min(a - b, b);
    for (int i = 0; i < b; i++) {
        fun(a - i, 1);
    }
    for (int i = b; i >= 1; i--) {
        fun(i, -1);
    }

    ///以下计算出了具体的数
    for (__typeof(m.begin()) it = m.begin(); it != m.end(); it++) {
        if ((*it).second != 0) {
            ret *= quick_pow((*it).first, (*it).second);
            ret %= mod;
        }
    }
    return ret;
}

int main()
{
    printf("%lld\n", C(5, 3));
    return 0;
}
