#include <bits/stdc++.h>

const int MAXN = 2100+5;

int k, n, m;
int f[MAXN][MAXN];
int dp[MAXN][MAXN];
int opt[MAXN][MAXN];
char a[MAXN], b[MAXN];

int main()
{
    while (~scanf("%s %s %d", a+1, b+1, &k)) {
        n = strlen(a+1), m = strlen(b+1);
        memset(dp, 0, sizeof dp);
        memset(f, 0, sizeof f);
        memset(opt, 0, sizeof opt);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i] == b[j]) {
                    f[i][j] = f[i-1][j-1] + 1;
                }
                else {
                    f[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (f[i][j] >= k) {
                    opt[i][j] = std::max(opt[i][j], dp[i-k][j-k] + k);
                    if (f[i][j] > k) {
                        opt[i][j] = std::max(opt[i][j], opt[i-1][j-1] + 1);
                    }
                }
                dp[i][j] = std::max(std::max(dp[i-1][j], dp[i][j-1]), opt[i][j]);
            }
        }
        printf("%d\n", dp[n][m]);
    }
}
