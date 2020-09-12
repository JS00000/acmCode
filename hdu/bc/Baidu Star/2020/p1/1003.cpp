#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int gcd[maxn][maxn];
int dp[maxn][maxn];

int main()
{
    memset(gcd, 0, sizeof(gcd));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (!gcd[i][j]) {
                for (int k = 1; k * i <= 1000 && k * j <= 1000; k++) {
                    gcd[i*k][j*k] = k;
                }
            }
        }
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + (gcd[i][j] == 1 ? 1 : 0);
        }
    }
    // for (int i = 1; i <= 10; i++) {
    //     for (int j = 1; j <= 10; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", dp[a][b]);
    }
    return 0;
}
