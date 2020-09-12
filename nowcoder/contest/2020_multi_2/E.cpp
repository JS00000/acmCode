#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
#define ll long long
 
using namespace std;

const int maxn = 5000 + 10;
const int maxk = 1000 + 10;
const ll inf = ~0llu>>1;
 
ll a[maxn];
ll dp[maxk][maxn];

int main()
{
    int n;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a+i);
        }
        int k = n / 2;
        for (int i = 0; i <= k; i++) 
            dp[i][0] = 0;
        for (int j = 0; j <= n; j++) 
            dp[0][j] = 0;
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = inf;
        for (int j = 2; j <= n; j++)
        {
            for (int i = 1; i <= k; i++)
            {
                if (2 * i <= j) {
                    //            not use j as C,          use j as C
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 2] + abs(a[j - 1] - a[j]));
                }
            }
        }
        printf("%d\n", dp[k][n]);   
    }
    return 0;
}
