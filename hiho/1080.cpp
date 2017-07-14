// 线段树 区间双标记
#include <cstdio>

using namespace std;

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int N = 1000070;

int sum[N<<2];
int alt[N<<2];
int add[N<<2];

inline void pushUP(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

inline void pushDown(int rt, int m)
{
    if (m == 1) return;
    if (alt[rt])
    {
        alt[rt<<1] = alt[rt<<1|1] = alt[rt];
        add[rt<<1] = add[rt<<1|1] = 0;
        sum[rt<<1] = (m-(m>>1))*alt[rt];
        sum[rt<<1|1] = (m>>1)*alt[rt];
        alt[rt]=0;
    }
    if (add[rt])
    {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += (m-(m>>1))*add[rt];
        sum[rt<<1|1] += (m>>1)*add[rt];
        add[rt]=0;
    }
}

void build(int l, int r, int rt)
{
    alt[rt] = 0;
    add[rt] = 0;
    if (l == r)
    {
        scanf("%d", sum+rt);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUP(rt);
}

void update(int L, int R, int c1, int c2, int l, int r, int rt)
{
    pushDown(rt, r-l+1);
    if(L<=l&&R>=r)
    {
        alt[rt] = c1;
        add[rt] = c2;
        if (c1) sum[rt]  = c1*(r-l+1);
        if (c2) sum[rt] += c2*(r-l+1);
        return ;
    }
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c1, c2, lson);
    if (R >  m) update(L, R, c1, c2, rson);
    pushUP(rt);
}

// int query(int L, int R, int l, int r, int rt)
// {
//     if (L<=l && r<=R) return sum[rt];
//     pushDown(rt, r-l+1);
//     int m = (l + r) >> 1;
//     int ret = 0;
//     if (L <=m) ret += query(L, R, lson);
//     if (R > m) ret += query(L, R, rson);
//     return ret;
// }

int main(int argc, char const *argv[])
{
    int n, q;
    scanf("%d%d", &n, &q);
    build(0, n, 1);
    int p, a, b, c;
    for (int i = 0; i < q; ++i)
    {
        scanf("%d%d%d%d", &p, &a, &b, &c);
        if (p == 0) update(a, b, 0, c, 0, n, 1);
        else        update(a, b, c, 0, 0, n, 1);
        printf("%d\n", sum[1]);
    }
    return 0;
}
