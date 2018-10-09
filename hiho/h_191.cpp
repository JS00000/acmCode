#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

int n, m;
int f[maxn][maxn][maxn];

struct point
{
    int x, y;
    point(){}
    point(int a, int b) : x(a), y(b) {}
    friend point operator-(const point &a, const point &b) 
    {
        return point(a.x - b.x, a.y - b.y);
    }
} p[maxn];

int det(const point &a, const point &b)
{
    return a.x * b.y - a.y * b.x;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) 
        scanf("%d%d", &p[i].x, &p[i].y);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        f[i][i+1][2] = 0;
        for (int j = i + 2; j < n; j++) {
            for (int k = 3; k <= m; k++) {
                f[i][j][k] = 0;
                for (int l = i + 1; l < j; l++) {
                    f[i][j][k] = max(f[i][j][k], f[i][l][k-1] + det(p[l] - p[i], p[j] - p[i]));
                }
                ans = max(ans, f[i][j][k]);
            }
        }
    }
    printf("%.2f\n", double(ans) / 2);
    return 0;
}
