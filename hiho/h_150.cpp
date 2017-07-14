#include <cstdio>
#include <algorithm>

#define maxn 107

using namespace std;

bool g[maxn][maxn];
int f[maxn][maxn][2];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n+1; i++) {
        g[i][0] = 1;
        g[i][m+1] = 1;
    }
    for (int i = 0; i <= m+1; i++) {
        g[0][i] = 1;
        g[n+1][i] = 1;
    }
    char mp[maxn];
    for (int i = 1; i <= n; i++) {
        scanf("%s", mp);
        for (int j = 0; j < m; j++) g[i][j+1] = mp[j] == 'b';
    }
    f[1][1][0] = g[1][1];
    f[1][1][1] = g[1][1] + !g[1][2];
    for (int i = 2; i <= n; i++) {
        f[i][1][0] = min(   f[i-1][1][0] + g[i][1] + !g[i-1][2] + !g[i+1][1], 
                            f[i-1][1][1] + g[i][1] + !g[i+1][1]);
        f[i][1][1] = min(   f[i-1][1][0] + g[i][1] + !g[i-1][2], 
                            f[i-1][1][1] + g[i][1]);
    }
    for (int i = 2; i <= m; i++) {
        f[1][i][0] = min(   f[1][i-1][0] + g[1][i], 
                            f[1][i-1][1] + g[1][i] + !g[2][i-1]);
        f[1][i][1] = min(   f[1][i-1][0] + g[1][i] + !g[1][i+1], 
                            f[1][i-1][1] + g[1][i] + !g[2][i-1] + !g[1][i+1]);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            f[i][j][0] = min(min(min(   f[i-1][j][0] + g[i][j] + !g[i-1][j+1] + !g[i+1][j],
                                        f[i-1][j][1] + g[i][j] + !g[i+1][j]),
                                        f[i][j-1][0] + g[i][j]),
                                        f[i][j-1][1] + g[i][j] + !g[i+1][j-1]);

            f[i][j][1] = min(min(min(   f[i-1][j][0] + g[i][j] + !g[i-1][j+1],
                                        f[i-1][j][1] + g[i][j]),
                                        f[i][j-1][0] + g[i][j] + !g[i][j+1]),
                                        f[i][j-1][1] + g[i][j] + !g[i+1][j-1] + !g[i][j+1]);
        }
    }
    printf("%d\n", min(f[n][m][0], f[n][m][1]));
    return 0;
}