#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

char a[maxn][maxn];

bool check(int x, int y, char g)
{
    int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, 1, -1};
    for (int k = 0; k < 4; k++) {
        int cnt = 1;
        int tx = x;
        int ty = y;
        while (tx + dx[2*k] >= 0 && tx + dx[2*k] < 25 && ty + dy[2*k] >= 0 && ty + dy[2*k] < 25 && a[tx + dx[2*k]][ty + dy[2*k]] == g) {
            cnt++;
            tx += dx[2*k];
            ty += dy[2*k];
        }
        tx = x;
        ty = y;
        while (tx + dx[2*k+1] >= 0 && tx + dx[2*k+1] < 25 && ty + dy[2*k+1] >= 0 && ty + dy[2*k+1] < 25 && a[tx + dx[2*k+1]][ty + dy[2*k+1]] == g) {
            cnt++;
            tx += dx[2*k+1];
            ty += dy[2*k+1];
        }
        if (cnt >= 5) return true;
    }
    return false;
}

int main()
{
    int x = 0;
    int o = 0;
    for (int i = 0; i < 25; i++) {
        scanf("%s", a[i]);
        for (int j = 0; j < 25; j++) {
            if (a[i][j] == 'x') {
                x++;
            } else if (a[i][j] == 'o') {
                o++;
            }
        }
    }
    char g;
    if (x == o) g = 'x';
    else g = 'o';
    bool flag = true;
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 25; j++)
            if ((a[i][j] == '.') && check(i, j, g)) {
                printf("%d %d\n", i, j);
                flag = false;
            }
    if (flag) printf("tie\n");
    return 0;
}
