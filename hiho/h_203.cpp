#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 507
using namespace std;

int H, W, cm = 0, cs = 0;
char a[maxn][maxn];
int flag1[maxn][maxn];
int flag2[maxn][maxn];
int qx[maxn*maxn], qy[maxn*maxn];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int check(int x, int y)
{
    int i = 0, iq = 1, qn = 0;
    qx[0] = x, qy[0] = y;
    flag1[x][y] = 1;
    flag2[x][y] = 1;
    int minx = 1000, miny = 1000, maxx = 0, maxy = 0;
    while (i < iq) {
        x = qx[i], y = qy[i];
        for (int k = 0; k < 8; k++) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if (tx > 0 && tx <= H && ty > 0 && ty <= W && !flag1[tx][ty]) {
                if (a[tx][ty] == '#') {
                    qx[iq] = tx;
                    qy[iq] = ty;
                    iq++;
                    minx = min(minx, tx);
                    miny = min(miny, ty);
                    maxx = max(maxx, tx);
                    maxy = max(maxy, ty);
                    flag2[tx][ty] = 1;
                }
                flag1[tx][ty] = 1;
            }
        }
        i++;
    }

    qx[0] = qx[iq-1];
    qy[0] = qy[iq-1];
    iq = 1;
    i = 0;
    flag2[qx[0]][qy[0]] = 0;
    while (i < iq) {
        x = qx[i], y = qy[i];
        for (int k = 0; k < 8; k++) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if (tx > 0 && tx <= H && ty > 0 && ty <= W && flag2[tx][ty]) {
                qx[iq] = tx;
                qy[iq] = ty;
                iq++;
                flag2[tx][ty] = 0;
            }
        }
        i++;
    }

    double cx = (minx + maxx) / 2.0;
    double cy = (miny + maxy) / 2.0;
    double mx = (qx[0] + qx[iq-1]) / 2.0;
    double my = (qy[0] + qy[iq-1]) / 2.0;

    // a[qx[0]][qy[0]] = 'P';
    // a[qx[iq-1]][qy[iq-1]] = 'Q';    
    // a[int(cx+0.5)][int(cy+0.5)] = 'C';
    // if (a[int(mx+0.5)][int(my+0.5)] == 'C') a[int(mx+0.5)][int(my+0.5)] = 'T';
    // else a[int(mx+0.5)][int(my+0.5)] = 'M';

    double r = ( ((cx - mx) * (cx - mx) + (cy - my) * (cy - my)) / ( (qx[0] - qx[iq-1]) * (qx[0] - qx[iq-1]) + (qy[0] - qy[iq-1]) * (qy[0] - qy[iq-1]) ) );
    // printf("%f\n", r);
    return r < 0.16;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &H, &W);
    for (int i = 1; i <= H; i++) 
        scanf("%s", a[i]+1);
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            if (!flag1[i][j] && a[i][j] == '#') {
                if (check(i, j)) cs++;
                else cm++;
            }
    // for (int i = 1; i <= H; i++) {
    //     for (int j = 1; j <= W; j++) {
    //         printf("%c", a[i][j]);
    //     } 
    //     printf("\n");
    // }
    printf("%d %d\n", cm, cs);
    return 0;
}
