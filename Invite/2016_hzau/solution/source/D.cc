#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
using namespace std;

const int MAXN = 55;
const int MAXM = 505;
int N, M, K;
double dp[MAXN][MAXM], all[MAXN][MAXM];

void input()
{
    scanf("%d%d%d", &N, &M, &K);
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    memset(all, 0, sizeof(all));
    dp[0][0] = all[0][0] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int k = i - 1; k <= M - N + i -1; k++)
        {
            if(i == N)
                dp[i][M - k] = all[i - 1][k];
            else
            {
                for(int j = 1; j <= M - N + i - k; j++)
                {
                    double p = all[i - 1][k]/(M - N + i - k);
                    dp[i][j] += p;
                    all[i][j + k] += p;
                }
            }
        }
        if(i == K)
        {
            double ans = 0;
            for(int i = 1; i <= M - N + 1; i++)
                ans += i*dp[K][i];
            printf("%.6f\n", ans);
            return;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        input();
        solve();
    }
    return 0;
}
