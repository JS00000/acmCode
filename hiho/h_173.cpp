#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int n;
int a[maxn], sum[maxn];
int dp[maxn][maxn][2];

int main()
{
    sum[0] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        sum[i] = sum[i-1] + a[i];
        dp[i][i][0] = a[i];
        dp[i][i][1] = 0;
    }
    for (int k = 1; k < n; k++) {
        for (int i = 1; i + k <= n; i++) {
            dp[i][i+k][0] = max(a[i] + dp[i+1][i+k][1], a[i+k] + dp[i][i+k-1][1]);
            dp[i][i+k][1] = sum[i+k] - sum[i-1] - dp[i][i+k][0];
        }
    }
    printf("%d\n", dp[1][n][0]);
    return 0;
}
