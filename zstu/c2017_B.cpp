// 多边形类
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100007;

struct point
{
    int x,y;
    point(){}
    point(int a, int b) : x(a), y(b) {}
    friend point operator+(const point &a, const point &b)
    {
        return point(a.x+b.x, a.y+b.y);
    }
    friend point operator-(const point &a, const point &b)
    {
        return point(a.x-b.x, a.y-b.y);
    }
};
int det(const point &a, const point &b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(const point &a, const point &b)
{
    return a.x*b.x+a.y*b.y;
}

int n, m;
int a, b, minx = 10000, miny = 10000, maxx = 0, maxy = 0;
point p[maxn];
short mp[2017][2017];

void walk(point p1, point p2, point d1, point d2)
{
    point pw = p1, pt = p2 - p1;
    while(pw.x != p2.x || pw.y != p2.y)
    {
        if (det(pt, pw + d1 - p1) >= 0) pw = pw + d1;
        else pw = pw + d2;
        if (pw.x < minx || pw.y < miny || pw.x > maxx || pw.y > maxy) return;
        mp[pw.x][pw.y] = 1;
    }
}

void bfs(int x, int y)
{
    queue<int> qx, qy;
    qx.push(x);qy.push(y);
    while(!qx.empty())
    {
        x = qx.front(), y = qy.front();
        qx.pop(), qy.pop();
        mp[x][y] = 2;
        if (mp[x+1][y] == 0) qx.push(x+1), qy.push(y);
        if (mp[x-1][y] == 0) qx.push(x-1), qy.push(y);
        if (mp[x][y+1] == 0) qx.push(x), qy.push(y+1);
        if (mp[x][y-1] == 0) qx.push(x), qy.push(y-1);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a, &b), p[i].x = a + 1008, p[i].y = b + 1008, 
        minx = min(minx, p[i].x), miny = min(miny, p[i].y), 
        maxx = max(maxx, p[i].x), maxy = max(maxy, p[i].y);
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < n; ++i)
    {
        point p1 = p[i], p2 = p[(i+1)%n], pt = p2 - p1;
        if (pt.x > 0 && pt.y >= 0)      walk(p1, p2, point(1, 0), point(0, 1));
        else if (pt.x <= 0 && pt.y > 0) walk(p1, p2, point(0, 1), point(-1, 0));
        else if (pt.x < 0 && pt.y <= 0) walk(p1, p2, point(-1, 0), point(0, -1));
        else if (pt.x >= 0 && pt.y < 0) walk(p1, p2, point(0, -1), point(1, 0));
    }

    for (int i = minx-2; i <= maxx+2; ++i) mp[i][maxy+2] = 2;
    for (int i = minx-2; i <= maxx+2; ++i) mp[i][miny-2] = 2;
    for (int j = miny-2; j <= maxy+2; ++j) mp[minx-2][j] = 2;
    for (int j = miny-2; j <= maxy+2; ++j) mp[maxx+2][j] = 2;

    // bfs(minx-1, miny-1);

    for (int j = maxy+3; j >= miny-3; --j)
    {
        for (int i = minx-3; i <= maxx+3; ++i)
            printf("%d ", mp[i][j]);
        printf("\n");
    }

    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &a, &b), a += 1008, b += 1008;
        if (a > maxx || b > maxy || a < minx || b < miny) printf("No\n");
        else if (mp[a][b] == 2) printf("No\n");
        else printf("Yes\n");
    }

    return 0;
}
