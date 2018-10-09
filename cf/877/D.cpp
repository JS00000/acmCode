#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int n, m, k, x1, y1, x2, y2;
int f[maxn][maxn];
char mp[maxn][maxn];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};


bool bfs()
{
    int qx[maxn*maxn], qy[maxn*maxn], iq = 1, i = 0;
    qx[0] = x1;
    qy[0] = y1;
    f[x1][y1] = 0;
    if (x1 == x2 && y1 == y2) return 1;
    bool flag = 0;
    while (i < iq) {
        int x = qx[i], y = qy[i];
        for (int j = 0; j < 4; j++) {
            int tx = x, ty = y, loop = k;
            while (loop--) {
                tx += dx[j];
                ty += dy[j];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) break;
                if (mp[tx][ty] == '#') break;
                if (f[tx][ty] <= f[x][y]) break;
                if (f[tx][ty] == f[x][y] + 1) continue;
                f[tx][ty] = f[x][y] + 1;
                qx[iq] = tx;
                qy[iq++] = ty;
                if(tx == x2 && ty == y2) return 1;
            }
        }
        i++;
    }
    return 0;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%s", mp[i]);
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            f[i][j] = 0x7fffffff;
    x1--;x2--;y1--;y2--;
    if (bfs()) printf("%d\n", f[x2][y2]);
    else printf("-1\n");
    return 0;
}
