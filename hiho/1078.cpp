// 线段树 区间标记
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

#define LL long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int N = 1000007;

LL sum[N<<2];
LL add[N<<2];

inline void pushUP(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

inline void pushDown(int rt, int m)
{
    if (add[rt])
    {
        add[rt<<1] = add[rt];
        add[rt<<1|1] = add[rt];
        sum[rt<<1] = (m-(m>>1))*add[rt];
        sum[rt<<1|1] = (m>>1)*add[rt];
        add[rt]=0;
    }
}

void build(int l, int r, int rt)
{
    add[rt] = 0;
    if (l == r)
    {
        scanf("%lld", sum+rt);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUP(rt);
}

void update(int L, int R, int sc, int l, int r, int rt)
{
    if(L<=l&&R>=r)
    {
        add[rt] = sc;
        sum[rt] = (LL)sc*(r-l+1);
        return ;
    }
    pushDown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, sc, lson);
    if (R>m) update(L, R, sc, rson);
    pushUP(rt);
}

LL query(int L, int R, int l, int r, int rt)
{
    if (L<=l && r<=R) return sum[rt];
    pushDown(rt, r-l+1);
    int m = (l + r) >> 1;
    LL ret = 0;
    if (L<=m) ret += query(L, R, lson);
    if (R>m) ret += query(L, R, rson);
    return ret;
}

int main(int argc, char const *argv[])
{
    int n, q, w;
    scanf("%d", &n);
    build(1, n, 1);
    scanf("%d", &q);
    int p, a, b, c;
    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &p);
        if (p == 0)
        {
            scanf("%d%d", &a, &b);
            printf("%lld\n", query(a, b, 1, n, 1));
        }
        else
        {
            scanf("%d%d%d", &a, &b, &c);
            update(a, b, c, 1, n, 1);
        }
    }
    return 0;
}
