#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 300007
using namespace std;
typedef long long ll;

int n, m;
ll w[2][maxn], ma[maxn];
ll pw[2][maxn], pma[maxn];

struct node
{
    node() {};
    node(int _l, int _r, ll _c) 
    {
        l = _l;
        r = _r;
        c = _c;
    };
    int l, r;
    ll c;
};

node intervals[2][maxn];
ll sum[2][maxn];

bool cmp(node x, node y)
{
    return x.r < y.r;
}

int main()
{
    pw[0][0] = 0;
    pw[1][0] = 0;
    pma[0] = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", w[1]+i);
        pw[1][i] = pw[1][i-1] + w[1][i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", w[0]+i);
        pw[0][i] = pw[0][i-1] + w[0][i];
        ma[i] = max(w[0][i], w[1][i]);
        pma[i] = pma[i-1] + ma[i];
    }
    int mm[2] = {0, 0};
    for (int i = 1; i <= m; i++) {
        int t, l, r;
        ll c;
        scanf("%d%d%d%lld", &t, &l, &r, &c);
        int tt = t%2;
        mm[tt]++;
        intervals[tt][mm[tt]] = node(l, r, c);
    }
    sort(intervals[0] + 1, intervals[0] + 1 + mm[0], cmp);
    sort(intervals[1] + 1, intervals[1] + 1 + mm[1], cmp);
    sum[0][0] = 0;
    sum[1][0] = 0;
    int im[2] = {1, 1};
    while (im[0] < mm[0] || im[1] < mm[1]) {
        int tt;
        if (im[0] == mm[0])
            tt = 1;
        else if (im[1] == mm[1])
            tt = 0;
        else 
            tt = (intervals[0][im[0]].r < intervals[1][im[1]].r) ? 0: 1;
        // choose im[tt]
        bool flag = true;
        int l = intervals[tt][im[tt]].l;
        int r = intervals[tt][im[tt]].r;
        ll c = intervals[tt][im[tt]].c;
        // find tt^1
        for (int j = 1; j < im[tt^1]; j++) {
            if (intervals[tt^1][j].r < intervals[tt][im[tt]].l) {
                sum[tt][im[tt]] = max(sum[tt^1][j] + c + pw[tt][r] - pw[tt][l-1] - (pma[r] - pma[l-1]), sum[tt][im[tt]-1]);
                flag = false;
            }
        }
        // find tt
        for (int j = 1; j < im[tt]; j++) {
            if (intervals[tt][j].r < intervals[tt][im[tt]].l) {
                sum[tt][im[tt]] = max(sum[tt][j] + c + pw[tt][r] - pw[tt][l-1] - (pma[r] - pma[l-1]), sum[tt][im[tt]-1]);
                flag = false;
            }
        }
        if (flag) 
            sum[tt][im[tt]] = max(pma[l-1] + c + pw[tt][r] - pw[tt][l-1], sum[tt][im[tt]-1]);
        im[tt]++;
    }
    ll maxi = pma[n];
    printf("%lld\n", max(sum[0][mm[0]], sum[1][mm[1]]));
    return 0;
}
