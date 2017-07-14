// 扫雷 core
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 57
using namespace std;

class bomb
{
    int n, m;
    short mp[maxn][maxn];
    // // mp[][]: 0~8 周围雷数, -1未知, -2已知是雷, -3当前轮判断一定是雷, -4当前轮判断一定不是雷, -5边界
    static const short di[8];
    static const short dj[8];
    bool check_simple()
    {
        bool ret = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                if (mp[i][j] == 0)
                    for (int k = 0; k < 8; ++k) 
                        if (mp[i+di[k]][j+dj[k]] == -1) mp[i+di[k]][j+dj[k]] = -4, ret = 1;
                if (mp[i][j] > 0)
                {
                    int uc = 0, mpc = mp[i][j];
                    for (int k = 0; k < 8; ++k)
                    {
                        if (mp[i+di[k]][j+dj[k]] == -1) uc++;
                        if (mp[i+di[k]][j+dj[k]] == -3 || mp[i+di[k]][j+dj[k]] == -2) mpc--;
                    }
                    if (uc == mpc)
                        for (int k = 0; k < 8; ++k)
                            if (mp[i+di[k]][j+dj[k]] == -1) mp[i+di[k]][j+dj[k]] = -3, ret = 1;
                    if (mpc == 0)
                        for (int k = 0; k < 8; ++k)
                            if (mp[i+di[k]][j+dj[k]] == -1) mp[i+di[k]][j+dj[k]] = -4, ret = 1;
                }
            }
        return ret;
    }

    bool search(short p[][maxn], int x, int y, int t)
    {
        bool ret = 1;
        p[x][y] = t;
        for (int k = 0; k < 8; ++k)
        {
            int i = x+di[k], j = y+dj[k];
            if (0<i && i<=n && 0<j && j<=m && mp[i][j] > 0)
            {
                int uc = 0, mpc = mp[i][j];
                for (int k2 = 0; k2 < 8; ++k2)
                {
                    if (mp[i+di[k2]][j+dj[k2]] == -1 && p[i+di[k2]][j+dj[k2]] == 0) uc++;
                    if (mp[i+di[k2]][j+dj[k2]] == -2 || mp[i+di[k2]][j+dj[k2]] == -3 || p[i+di[k2]][j+dj[k2]] == 1) mpc--;
                }
                if (mpc < 0 || mpc > uc) return 0;
                if (uc == mpc)
                    for (int k2 = 0; k2 < 8; ++k2)
                        if (mp[i+di[k2]][j+dj[k2]] == -1 && p[i+di[k2]][j+dj[k2]] == 0)
                            ret = search(p, i+di[k2], j+dj[k2], 1);
                if (mpc == 0)
                    for (int k2 = 0; k2 < 8; ++k2)
                        if (mp[i+di[k2]][j+dj[k2]] == -1 && p[i+di[k2]][j+dj[k2]] == 0)
                            ret = search(p, i+di[k2], j+dj[k2], -1);
            }
        }
        return ret;
    }

    bool check_search()
    {
        short maxi = 10, x, y;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (mp[i][j] == -1)
                    for (int k = 0; k < 8; ++k)
                        if (mp[i+di[k]][j+dj[k]] > 0 && mp[i+di[k]][j+dj[k]] < maxi)
                            maxi = mp[i+di[k]][j+dj[k]], x = i, y = j;
        if (maxi == 10) return 0;
        short flag[maxn][maxn], p[maxn][maxn];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                flag[i][j] = 0, p[i][j] = 0;
        if (search(p, x, y, 1))
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j) flag[i][j] += p[i][j];
        else {mp[x][y] = -4; return 1;}
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                p[i][j] = 0;
        if (search(p, x, y, -1))
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j) flag[i][j] += p[i][j];
        else {mp[x][y] = -3; return 1;}
        bool ret = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                if (flag[i][j] == 2) mp[i][j] = -3, ret = 1;
                if (flag[i][j] == -2) mp[i][j] = -4, ret = 1;
            }
        return ret;
    }
public:
    bomb(){};
    ~bomb(){};
    void input()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%hd", &mp[i][j]);
        for (int i = 0; i <= n+1; ++i) mp[i][0] = mp[i][m+1] = -5;
        for (int i = 0; i <= m+1; ++i) mp[0][i] = mp[n+1][i] = -5;
    }
    void solve()
    {
        bool L1 = 0;
        while(!L1)
        {
            bool L2 = 0;
            while(!L2)
            {
                L2 = 1;
                if (check_simple()) L2 = 0;
            }
            L1 = 1;
            if (check_search()) L1 = 0;
        }
        int count1 = 0, count2 = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (mp[i][j] == -3) count1++;
                else if (mp[i][j] == -4) count2++;
        printf("%d %d\n", count1, count2);
    }
};

const short bomb::di[8] = {-1,-1,-1,0,0,1,1,1};
const short bomb::dj[8] = {-1,0,1,-1,1,-1,0,1};

int main()
{
    // freopen("1120.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        bomb B;
        B.input();
        B.solve();
    }
    return 0;
}
