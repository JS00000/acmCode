#include <ctime>
#include <cstdio>
#define maxn 154
using namespace std;

int mp[maxn][maxn];
int a[22] = {2,5,9,11,16,17,19,21,22,24,26,30,31,33,35,36,41,50,52,46,47,61};
bool flag[22];

void fill(int x, int y, int c, int id)
{
    for (int i = x; i < x+c; ++i)
        for (int j = y; j < y+c; ++j)
            mp[i][j] = id;
}

void dfs(int x, int y, int k, int n)
{
    int side = a[k];
    if (y + side > maxn) return;
    for (int j = y; j < y+side; ++j)
        if (mp[x][j]) return;

    fill(x, y, side, side);
    flag[k] = 1;

    if (n == 0)
    {
        for (int i = 0; i < maxn - 1; ++i)
            if (mp[maxn-1][i] != mp[maxn-1][i+1]) printf("%d ", mp[maxn-1][i]);
        printf("%d\n", mp[maxn-1][maxn-1]);
        return;
    }

    int tx = x, ty = y;
    while(mp[tx][ty])
    {
        ty++;
        if (ty == maxn) ty = 0, tx++;
    }

    for (int i = 0; i < 19; ++i)
        if (!flag[i]) dfs(tx, ty, i, n-1);

    fill(x, y, side, 0);
    flag[k] = 0;
}

int main()
{
    double start = clock();
    for (int i = 0; i < 22; ++i) flag[i] = 0;
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxn; ++j)
            mp[i][j] = 0;

    fill(0, 0, 47, 47);
    fill(0, 47, 46, 46);
    fill(0, 93, 61, 61);
    
    for (int i = 0; i < 19; ++i)
        dfs(46, 47, i, 18);

    double finish = clock();
    printf("%f\n", finish - start);
    return 0;
}
