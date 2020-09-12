#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        ll ans = 0;
        if (m * 2 <= n) ans = (2 * n - 2 * m - 2) * m + m;
        else ans = n * (n - 1) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}
