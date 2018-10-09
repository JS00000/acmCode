// WA
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 507
using namespace std;

int H, W, cm = 0, cs = 0;
char a[maxn][maxn];
int flag[maxn][maxn];
int qx[maxn*maxn], qy[maxn*maxn];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int check(int x, int y)
{
    int cnt = 0;
    for (int k = 0; k < 8; k++) {
        int tx = x + dx[k];
        int ty = y + dy[k];
        if (tx > 0 && tx <= H && ty > 0 && ty <= W)
            if (a[tx][ty] == '#') 
                cnt++;
    }
    return cnt >= 6;
}

int bfs(int x, int y)
{
    int i = 0, iq = 1, qn = 0;
    qx[0] = x, qy[0] = y;
    flag[x][y] = 1;
    while (i < iq) {
        x = qx[i], y = qy[i];
        for (int k = 0; k < 8; k++) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if (tx > 0 && tx <= H && ty > 0 && ty <= W && !flag[tx][ty]) {
                if (a[tx][ty] == '#') {
                    qx[iq] = tx;
                    qy[iq] = ty;
                    flag[tx][ty] = 1;
                    iq++;
                } else if (a[tx][ty] == '.') {
                    if (check(tx, ty)) 
                        qn++;
                    flag[tx][ty] = 1;
                }
            }
        }
        i++;
    }
    return qn >= 2;
}

int main()
{
    // freopen("h_203.in", "r", stdin);
    scanf("%d%d", &H, &W);
    for (int i = 1; i <= H; i++) 
        scanf("%s", a[i]+1);
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            if (!flag[i][j] && a[i][j] == '#') {
                if (bfs(i, j)) cm++;
                else cs++;
            }
    printf("%d %d\n", cm, cs);
    return 0;
}
