#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int cmp(double a, double b)
{
    return ((fabs(a - b) < 1e-8) ? 0 : (a < b ? -1: 1));
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, v;
    while(~scanf("%d%d", &n, &v))
    {
        double pos = 0, ans = 0, ti, posd;
        int a, vi;
        bool flag = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &a, &vi);
            posd = a + vi * ans;
            if (flag || !cmp(posd,pos)) continue;
            if (cmp(posd,pos) == -1)
            {
                if (vi < 0 && -vi >= v)
                {
                    flag = 1;
                    continue;
                }
                ti = (pos - posd) / (v + vi);
                ans += ti;
                pos -= v * ti;
            }
            else if (cmp(posd,pos) == 1)
            {
                if (vi >= v)
                {
                    flag = 1;
                    continue;
                }
                ti = (posd - pos) / (v - vi);
                ans += ti;
                pos += v * ti;
            }
            //printf("%.2lf\n", ans);
        }
        if (flag) printf("Bad Dog\n");
        else printf("%.2lf\n", fabs(ans));
        //printf("ffffffffffffffff\n");
    }
    return 0;
}
