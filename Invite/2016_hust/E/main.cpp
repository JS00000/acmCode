#include <cstdio>
#include <cstring>

using namespace std;

char pic[6][16] = {"+----+..",
                   "|++++|/.",
                   "|HUST|/+",
                   "+----+/|",
                   "./----/|",
                   "..+----+"};

char ans[1024][1024];
int n, m, i, j, k, px, py, px1, maxx, maxy;
int mp[107][107];

void draw(int x, int y)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (pic[i][j] != '.')
            {
                ans[x + i][y + j] = pic[i][j];
            }
        }
    }
    if (x + 5 > maxx) maxx = x + 5;
    if (y + 7 > maxy) maxy = y + 7;
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        maxx = maxy = 0;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                scanf("%d", &(mp[i][j]));
            }
        }
        memset(ans, '.', sizeof(ans));
        for (i = n; i > 0; i--)
        {
            px = i * 2 - 1;
            py = i * 2 - 6;
            for (j = 1; j <= m; j++)
            {
                py += 5;
                px1 = px - 3;
                for (k = 1; k <= mp[n - i + 1][j]; k++)
                {
                    px1 += 3;
                    draw(px1, py);
                }
            }
        }
        for (i = maxx; i > 0; i--)
        {
            for (j = 1; j <= maxy; j++)
            {
                printf("%c", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
