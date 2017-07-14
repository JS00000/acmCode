#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxL 117
#define maxn 100007
using namespace std;

int x[maxn], y[maxn], z[maxn], n;
int mp[maxL][maxL][maxL];
int visit[maxL][maxL][maxL];
int qx[maxL*maxL*maxL], qy[maxL*maxL*maxL], qz[maxL*maxL*maxL];
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};

bool valid(int i, int j, int k, int value)
{
    return mp[i-1][j][k] == value || mp[i+1][j][k] == value || mp[i][j-1][k] == value || mp[i][j+1][k] == value || mp[i][j][k-1] == value || mp[i][j][k+1] == value;
}

void merge(int i, int j, int k)
{
    int ql = 0, qr = 0;
    qx[qr] = i;
    qy[qr] = j;
    qz[qr] = k;
    visit[i][j][k] = 1;
    qr++;
    while (ql < qr) {
        i = qx[ql];
        j = qy[ql];
        k = qz[ql];
        // printf("%d %d %d %d\n", ql, i, j, k);
        mp[i][j][k] = -1;
        for (int kk = 0; kk < 6; kk++) {
            if (!visit[i + dx[kk]][j + dy[kk]][k + dz[kk]] && mp[i + dx[kk]][j + dy[kk]][k + dz[kk]] == 0) {
                visit[i + dx[kk]][j + dy[kk]][k + dz[kk]] = 1;
                qx[qr] = i + dx[kk];
                qy[qr] = j + dy[kk];
                qz[qr] = k + dz[kk];
                qr++;
            }
        }
        ql++;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i <= 103; i++)
            for (int j = 0; j <= 103; j++)
                for (int k = 0; k <= 103; k++)
                    mp[i][j][k] = 0, visit[i][j][k] = 0;
        for (int i = 0; i <= 103; i++)
            for (int j = 0; j <= 103; j++) {
                mp[i][j][0] = 1;
                mp[i][j][1] = 1;
                mp[i][0][j] = 1;
                mp[0][i][j] = 1;
                mp[i][j][103] = 1;
                mp[i][103][j] = 1;
                mp[103][i][j] = 1;
            }
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
            x[i]++;y[i]++;z[i]++;
            if (!valid(x[i], y[i], z[i], 1) || mp[x[i]][y[i]][z[i]]) flag = 1;
            mp[x[i]][y[i]][z[i]] = 1;
        }
        if (flag) {
            printf("No\n");
            continue;
        }
        merge(102,102,102);
        for (int i = n-1; i >= 0; i--) {
            if (!valid(x[i], y[i], z[i], -1)) {
                flag = 1;
                break;
            }
            merge(x[i], y[i], z[i]);
        }
        if (flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
