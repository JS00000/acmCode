#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x7fffffff
#define maxn 1007
using namespace std;

int n, m;
int a[maxn][maxn];
int dist[maxn];
bool p[maxn];

int prim_sub()
{
    for (int i = 1; i <= n; i++) {
        dist[i] = a[1][i];
        p[i] = 0;
    }
    p[1] = 1;
    int ret = 0;
    for (int i = 1; i < n; i++) {
        int k = 0, mi = inf, nn = 0;
        for (int j = 1; j <= n; j++) {
            if (!p[j] && dist[j] < mi) {
                mi = dist[j];
                k = j;
            }
        }
        for (int j = 1; j <= n; j++) {
            if (p[j] && a[k][j] == mi) nn++;
        }
        if (nn > 1) {
            return -1;
        }
        p[k] = 1;
        ret += mi;
        for (int j = 1; j <= n; j++) {
            if (!p[j] && a[k][j] < dist[j]) {
                dist[j] = a[k][j];
            }
        }
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                a[i][j] = inf;
            a[i][i] = 0;
        }
        int u, v, w;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            if (w < a[u][v]) {
                a[u][v] = w;
                a[v][u] = w;
            }
        }
        int t = prim_sub();
        if  (t == -1) printf("Not Unique!\n");
        else printf("%d\n", t);
    }
    return 0;
}
