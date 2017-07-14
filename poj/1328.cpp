#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 4007
using namespace std;

const double eps = 1e-6;
struct node
{
    double l, r;
};

bool cmp(node a, node b)
{
    return fabs(a.r - b.r) < eps ? a.l < b.l : a.r < b.r;
}

node pos[maxn];
bool p[maxn];

int main()
{
    int kase = 0, n, d, x, y;
    while(scanf("%d%d", &n, &d), !(n == 0 && d == 0))
    {
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            if (y - d > eps){
                flag = 1;
            }else{
                pos[i].l = x - sqrt(d*d-y*y);
                pos[i].r = x + sqrt(d*d-y*y);
            }
        }
        if (flag || (d < 0)) printf("Case %d: -1\n", ++kase);
        else
        {
            sort(pos, pos+n, cmp);
            memset(p, 0, sizeof(p));
            int ans = 0;
            for (int i = 0; i < n; i++)
                if (!p[i])
                {
                    p[i] = 1;
                    for (int j = 0; j < n; j++) if (!p[j] && pos[j].l < pos[i].r + eps) p[j] = 1;
                    ans++;
                }
            printf("Case %d: %d\n", ++kase, ans);
        }
    }
    return 0;
}
