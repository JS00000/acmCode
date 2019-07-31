#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 50007
#define inf 0x3f3f3f3f

int a[maxn],lt[maxn],rt[maxn],dp[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        dp[n+1] = dp[0] = lt[0] = rt[n+1] = -inf;
        for (int i = 1; i <= n; i++)
            dp[i] = max(dp[i-1] + a[i], a[i]);
        for (int i = 1; i <= n; i++)
            lt[i] = max(dp[i], lt[i-1]);
        for (int i = n; i >= 1; i--)
            dp[i] = max(dp[i+1] + a[i], a[i]);
        for (int i = n; i >= 1; i--)
            rt[i] = max(dp[i], rt[i+1]);
        int sum = -inf;
        for (int i = 1; i <= n; i++)
            sum = max(sum, lt[i] + rt[i+1]);
        printf("%d\n",sum);
    }
    return 0;
}
