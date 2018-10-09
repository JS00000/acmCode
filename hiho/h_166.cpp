#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

const int inf = 0x7fffffff;

int N, M, K, a, b, c, d;
char mp[maxn][maxn];
int dist[maxn][maxn][32];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int calc_k(char key)
{
    if (key >= 'a' && key <= 'z') return (1 << (key - 'a'));
    else return (1 << (key - 'A'));
}

void bfs()
{
    int qx[maxn*maxn*32], qy[maxn*maxn*32], qz[maxn*maxn*32], iq = 0, i = 0, x, y, z, tx, ty, tz;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 32; k++) {
                dist[i][j][k] = inf;
            }
        }
    }
    qx[iq] = a;
    qy[iq] = b;
    if (mp[a][b] >= 'a' && mp[a][b] <= 'z') qz[iq++] = calc_k(mp[a][b]);
    else qz[iq++] = 0;
    dist[a][b][qz[0]] = 0;
    bool flag = 0;
    while (i < iq) {
        x = qx[i];
        y = qy[i];
        z = qz[i];
        for (int k = 0; k < 4; k++) {
            tx = x + dx[k];
            ty = y + dy[k];
            if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
                if (mp[tx][ty] >= 'a' && mp[tx][ty] <= 'z') tz = z | calc_k(mp[tx][ty]);
                else tz = z;
                if (dist[tx][ty][tz] != inf) continue;
                else if (mp[tx][ty] == '.' || (mp[tx][ty] >= 'a' && mp[tx][ty] <= 'z') || (mp[tx][ty] >= 'A' && mp[tx][ty] <= 'Z' && (tz & calc_k(mp[tx][ty])) > 0)) {
                    qx[iq] = tx;
                    qy[iq] = ty;
                    qz[iq++] = tz;
                    dist[tx][ty][tz] = min(dist[tx][ty][tz], dist[x][y][z] + 1);
                    if (tx == c && ty == d) {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag) break;
        i++;
    }
}

int main()
{
    scanf("%d%d%d%d%d%d%d", &N, &M, &K, &a, &b, &c, &d);
    for (int i = 0; i < N; i++) scanf("%s", mp[i]);
    int tx, ty;
    for (int i = 0; i < K; i++) {
        scanf("%d%d", &tx, &ty);
        if (mp[tx][ty] == '.') mp[tx][ty] = 'a' + i;
    }
    bfs();
    int ans = inf;
    for (int k = 0; k < 32; k++) if (dist[c][d][k] < ans) ans = dist[c][d][k];
    if (ans == inf) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}
