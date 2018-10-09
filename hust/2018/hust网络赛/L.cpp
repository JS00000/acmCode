#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 1017

using namespace std;

int n;
int mp[maxn*2][maxn*2];
int flag[maxn*2][maxn*2];
int const offset = 1000;

struct tree
{
    int x, y;
}p[100007];

int ans[100007];

void dfs(int x, int y, int &st)
{
    if (mp[x-1][y] == -1 ||
        mp[x+1][y] == -1 ||
        mp[x][y-1] == -1 ||
        mp[x][y+1] == -1) 
        st = -1;
    if (x > 1 && mp[x-1][y] == 0 && !flag[x-1][y])
        dfs(x-1, y, st);
    if (x < 2000 && mp[x+1][y] == 0 && !flag[x+1][y])
        dfs(x+1, y, st);
    if (y > 0 && mp[x][y-1] == 0 && !flag[x][y-1])
        dfs(x, y-1, st);
    if (y < 2000 && mp[x][y+1] == 0 && !flag[x][y+1])
        dfs(x, y+1, st);
    mp[x][y] = st;
}

int check(int x, int y)
{
    if (mp[x+1][y] == -1)
        return 0;
    if (mp[x-1][y] == -1)
        return 0;
    if (mp[x][y+1] == -1)
        return 0;
    if (mp[x][y-1] == -1)
        return 0;
    return 1;
}

int dfs2(int x, int y) {
    int tot = 0;
    if (x > 0 && mp[x-1][y] == 2 && !flag[x-1][y])
        tot += dfs2(x-1, y) + 1;
    if (x < 2000 && mp[x+1][y] == 2 && !flag[x+1][y])
        tot += dfs2(x+1, y) + 1;
    if (y > 0 && mp[x][y-1] == 2 && !flag[x][y-1])
        tot += dfs2(x, y-1) + 1;
    if (y < 2000 && mp[x][y+1] == 2 && !flag[x][y+1])
        tot += dfs2(x, y+1) + 1;
    return tot;
}

int main()
{
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i <= 2000; i++) {
        mp[0][i] = -1;
        mp[2000][i] = -1;
        mp[i][0] = -1;
        mp[i][2000] = -1;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
        mp[p[i].x+offset][p[i].y+offset] = 1;
    }
    int last = 0;
    for (int i = 1; i < 2000; i++) {
        for (int j = 1; j < 2000; j++) {
            int st = 2;
            if (mp[i][j] == 0 && !flag[i][j])
                dfs(i, j, st);
            if (mp[i][j] == 2)
                last++;
        }
    }
    printf("1fin\n");
    memset(flag, 0, sizeof(flag));
    ans[n-1] = last;
    for (int i = n-2; i >= 0; i--) {
        ans[i] = ans[i+1];
        int x = p[i].x+offset;
        int y = p[i].y+offset;
        if (check(x, y)) {
            if ((x < 2000 && mp[x+1][y] == 2) ||
                (x > 0 && mp[x-1][y] == 2) ||
                (y < 2000 && mp[x][y+1] == 2) ||
                (x > 0 && mp[x][y-1] == 2))
                ans[i]++;
        } else {
            if (x < 2000 && mp[x+1][y] == 2)
                ans[i] -= dfs2(x+1, y);
            if (x > 0 && mp[x-1][y] == 2)
                ans[i] -= dfs2(x+1, y);
            if (y < 2000 && mp[x][y+1] == 2)
                ans[i] -= dfs2(x+1, y);
            if (y > 0 && mp[x][y-1] == 2)
                ans[i] -= dfs2(x+1, y);
        }
    }
    for (int i = 0; i < n; i++) 
        printf("%d\n", ans[i]);
    return 0;
}

