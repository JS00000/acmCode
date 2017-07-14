// 线段树 离散化
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 200007
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

int N, L, a[maxn], b[maxn], c[maxn];
int top[maxn<<2];
int lazyTag[maxn<<2];
bool flag[maxn];

inline void pushUP(int rt)
{
    top[rt] = (top[rt<<1] == top[rt<<1|1])? top[rt<<1] : 0;
}

inline void pushDown(int rt, int m)
{
    if (lazyTag[rt])
    {
        lazyTag[rt<<1] = lazyTag[rt];
        lazyTag[rt<<1|1] = lazyTag[rt];
        top[rt<<1] = lazyTag[rt];
        top[rt<<1|1] = lazyTag[rt];
        lazyTag[rt]=0;
    }
}

void build(int l, int r, int rt)
{
    lazyTag[rt] = 0;
    if (l == r)
    {
        top[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUP(rt);
}

void update(int L, int R, int id, int l, int r, int rt)
{
    if(L<=l&&R>=r)
    {
        lazyTag[rt] = id;
        top[rt] = id;
        return ;
    }
    pushDown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, id, lson);
    if (R >  m) update(L, R, id, rson);
    pushUP(rt);
}


void query(int L, int R, int l, int r, int rt)
{
    if (l == r)
    {
        flag[top[rt]] = 1;
        return;
    }
    pushDown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m) query(L, R, lson);
    if (R >  m) query(L, R, rson);
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &L);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d%d", a+i, b+i);
        c[2*i]   = a[i];
        c[2*i+1] = b[i];
    }
    int n = 2*N;
    sort(c, c+n);
    n = unique(c, c+n) - c;
    for (int i = 0; i < N; ++i)
    {
        a[i] = lower_bound(c, c+n, a[i]) - c + 1;
        b[i] = lower_bound(c, c+n, b[i]) - c;
    }
    
    build(1, n, 1);
    for (int i = 0; i < N; ++i)
        update(a[i], b[i], i+1, 1, n, 1);

    for (int i = 0; i <= N; ++i) flag[i] = 0;
    query(1, n, 1, n, 1);
    int sum = 0;
    for (int i = 1; i <= N; ++i)
        if (flag[i] != 0) sum++;
    printf("%d\n", sum);
            
    return 0;
}
