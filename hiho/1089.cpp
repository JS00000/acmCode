#include <cstdio>

using namespace std;
const int maxn = 107;

int n, m;
int mp[maxn][maxn];

void floyd()
{
    for (int k = 1; k <= n; k++)
        for ( int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (mp[i][j] - mp[k][j] > mp[i][k])
                    mp[i][j] = mp[i][k] + mp[k][j];
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) mp[i][j] = ~0u>>1;
        mp[i][i] = 0;
    }
    int u, v, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        if (mp[u][v] > c) mp[u][v] = c;
        if (mp[v][u] > c) mp[v][u] = c;
    }
    floyd();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", mp[i][j] == ~0u>>1 ? -1 : mp[i][j]);
        printf("\n");
    }
    printf("\n");
    return 0;
}

