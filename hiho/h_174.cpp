#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
double dp[107][607];


int main()
{
    scanf("%d%d", &n, &m);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 6; i++) {
        dp[1][i] = 100.0/6;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= i*6; j++) {
            for (int k = 1; k <= 6; k++) {
                dp[i][j] += dp[i-1][j-k] / 6;
            }
        }
    }
    printf("%.2f\n", dp[n][m]);
    return 0;
}
