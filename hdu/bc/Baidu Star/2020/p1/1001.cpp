#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

const int inf = 0x3f3f3f3f;
// int x[maxn], y[maxn];
// int dp[10007];
int n, m, x, y;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        int mini = inf;
        for (int i = 1; i <= n; i++) {
            // scanf("%d%d", x+i, y+i);
            scanf("%d%d", &x, &y);
            mini = min(mini, m / x * y + ((m % x) ? 1 : 0) * y);
        }
        printf("%d\n", mini);
        // dp[0] = 0;
        // for (int j = 1; j <= m; j++) {
        //     dp[j] = inf;
        // }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = x[i]; j <= m; j++) {
        //         dp[j] = min(dp[j], dp[j-x[i]]+y[i]);
        //     }
        // }

    }
    return 0;
}
