#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

int mp[maxn][maxn];
int qx[maxn*maxn], qy[maxn*maxn];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visit[maxn][maxn];

int main()
{
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &mp[i][j]);
            visit[i][j] = 0;
        }
    int s = mp[x][y];
    int iq = 0, i = 0, count = 1, sub = 0;
    qx[iq] = x;
    qy[iq++] = y;
    visit[x][y] = 1;
    while (i < iq) {
        x = qx[i];
        y = qy[i];
        for (int k = 0; k < 4; k++) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if (tx >= 0 && ty >= 0 && tx < n && ty < m && !visit[tx][ty] && mp[tx][ty] == s) {
                visit[tx][ty] = 1;
                qx[iq] = tx;
                qy[iq++] = ty;
                count++;
                for (int kk = 0; kk < 4; kk++) {
                    int ttx = tx + dx[kk];
                    int tty = ty + dy[kk];
                    if (ttx >= 0 && tty >= 0 && ttx < n && tty < m && visit[ttx][tty] && mp[ttx][tty] == s) 
                        sub++;
                }
            }
        }
        i++;
    }
    printf("%d\n", count*4 - sub*2);
    return 0;
}
