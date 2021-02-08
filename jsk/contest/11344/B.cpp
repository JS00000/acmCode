#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 300007
using namespace std;
typedef long long ll;


int n, m;
ll b[maxn], w[maxn], ma[maxn];
ll pb[maxn], pw[maxn], pma[maxn];


int main()
{
    pb[0] = 0;
    pw[0] = 0;
    ma[0] = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", b+i);
        pb[i] = pb[i-1] + b[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", w+i);
        ma[i] = max(b[i], w[i]);
        pw[i] = pw[i-1] + w[i];
        pma[i] = pma[i-1] + ma[i];
    }
    ll maxi = pma[n];
    for (int i = 1; i <= m; i++) {
        int t, l, r;
        ll c;
        scanf("%d%d%d%lld", &t, &l, &r, &c);
        ll ori = pma[r] - pma[l-1];
        ll now;
        if (t == 1) {
            now = pb[r] - pb[l-1] + c;
        } else {
            now = pw[r] - pw[l-1] + c;
        }
        if (now > ori) maxi += now - ori;
    }
    printf("%lld\n", maxi);
    return 0;
}
