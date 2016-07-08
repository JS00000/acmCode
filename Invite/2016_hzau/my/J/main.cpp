#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

bool flag[2016];
int num[2016];
int f[2016][2016];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, a, minx, maxx;
    while(~scanf("%d", &n))
    {
        if (!n)
        {
            printf("0\n");
            continue;
        }
        memset(flag, 0, sizeof(flag));
        memset(f, 0, sizeof(f));
        memset(num, 0, sizeof(num));
        int ans = 1;
        minx = 40000;
        maxx = -1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a);
            flag[a] = 1;
            num[a]++;
            if (num[a] > ans) ans = num[a];
            if (a > maxx) maxx = a;
            if (a < minx) minx = a;
        }
        
        for (int i = minx; i <= maxx; i++)
            if (flag[i])
                for (int j = 1; j <= maxx; j++)
                    f[i][j] = 1;
        int i = minx + 1;
        while(i <= maxx)
        {
            if (flag[i])
            {
                for (int j = 1; j <= maxx; j++)
                {
                    if ( (i - j >= minx) && flag[i-j])
                    {
                        f[i][j] = f[i-j][j] + 1;
                        if (ans < f[i][j]) ans = f[i][j];
                    }
                }
            }
            i++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
