#include <cstdio>
#include <algorithm>
#define maxn 100007
#define maxm 1007
using namespace std;
const unsigned long long inf = 0x7fffffffffffffff;
int a[maxn], b[maxn], k[maxm], p[maxm];
unsigned long long f[11][1001];

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; i++)
            scanf("%d%d", a+i, b+i);
        for (int i = 0; i < m; i++)
            scanf("%d%d", k+i, p+i);
        for (int d = 0; d <= 10; d++) {
            f[d][0] = 0;
            for (int i = 1; i <= 1000; i++)
                f[d][i] = inf;
        }
        for (int d = 0; d <= 10; d++)
            for (int i = 1; i <= 1000; i++)
                for (int j = 0; j < m; j++){
                    if (p[j] <= d) continue;
                    f[d][i] = min(f[d][i], f[d][max(0, i - p[j] + d)] + k[j]);
                }
        unsigned long long tot = 0;
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            if (f[b[i]][a[i]] == inf) {
                flag = 1;
                break;
            }
            tot += f[b[i]][a[i]];
        }
        if (flag) printf("-1\n");
        else printf("%llu\n", tot);
    }
    return 0;
}
