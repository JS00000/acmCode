#include <cstdio>
int a[3007];
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; i++) a[i] = 0;
        int u, v, k;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &k);
            if (u == v) continue;
            a[u] += k;
            a[v] += k;
        }
        int mina = a[1];
        for (int i = 2; i <= n; i++)
            if (a[i] < mina) mina = a[i];
        printf("%d\n", mina);
    }
    return 0;
}
