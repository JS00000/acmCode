#include <cstdio>
#include <algorithm>
#define maxn 1007

using namespace std;

int n, m, s, t;
int a[maxn];

class P
{
public:
    int x, y;
    P(){}
    P(int _x, int _y):x(_x), y(_y){}
    P operator+(const int &s) const
    {
        if (this->y+s < a[this->x]) return P(this->x, this->y+s);
        else return P(this->x+1, 0);
    }
    static bool cmp(const P& p1, const P& p2)
    {
        return p1.x == p2.x ? p1.y < p2.y: p1.x < p2.x;
    }
};

P f[maxn][maxn];

int main()
{
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        scanf("%d%d%d%d", &n, &m, &s, &t);
        for (int i = 0; i < n; ++i)
            scanf("%d", a+i);
        a[n] = 10000000;
        f[0][0] = P(0,0);
        int ans = m+1;
        for (int i = 1; i <= m; ++i)
        {
            f[0][i] = f[0][i-1] + s;
            f[i][0] = f[i-1][0] + t;
            if (f[0][i].x >= n && i < ans) ans = i;
            if (f[i][0].x >= n) ans = 0;
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (i+j > m) continue;
                f[i][j] = max(f[i-1][j] + t, f[i][j-1] + s, P::cmp);
                if (f[i][j].x >= n && j < ans) ans = j;
            }
        }
        if (ans == m+1) printf("No\n");
        else printf("%d\n", ans);
    }
    return 0;
}
