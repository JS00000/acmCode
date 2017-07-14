#include <cstdio>
#include <algorithm>
#define maxn 1007
#define LL long long
using namespace std;

int N, M, n;

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
} p[maxn];

LL det(point p1, point p2)
{
    return (1ll)*p1.x*p2.y - (1ll)*p2.x*p1.y;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++i)
            scanf("%d%d", &p[i].x, &p[i].y);
        n = 2;
        for (int i = 2; i < N; ++i)
        {
            if (det(p[i]-p[n-1], p[n-1]-p[n-2]) == 0) n--;
            p[n++] = p[i];
        }
        if (det(p[1]-p[0], p[0]-p[n-1]) == 0) p[0] = p[--n];
        point pmin, pmax;
        bool flag = 0;
        for (int i = 0; i < n; ++i)
        {
            point p1 = p[i], p2 = p[(i+1)%n], p3 = p[(i+2)%n], p4 = p[(i+3)%n];
            point pmin2, pmin3, pmax2, pmax3;
            pmin2 = p2, pmax2 = p2;
            if (det(p2-p1, p3-p2) > 0)
            {
                if (p1.x > p2.x || p1.y > p2.y) pmin2.x -= M;
                if (p1.x < p2.x || p1.y > p2.y) pmin2.y -= M;
                if (p1.x < p2.x || p1.y < p2.y) pmax2.x += M;
                if (p1.x > p2.x || p1.y < p2.y) pmax2.y += M;
            }
            else
            {
                if (p1.x < p2.x || p1.y > p2.y) pmin2.x -= M;
                if (p1.x < p2.x || p1.y < p2.y) pmin2.y -= M;
                if (p1.x > p2.x || p1.y < p2.y) pmax2.x += M;
                if (p1.x > p2.x || p1.y > p2.y) pmax2.y += M;
            }
            pmin3 = p3, pmax3 = p3;
            if (det(p3-p2, p4-p3) > 0)
            {
                if (p2.x > p3.x || p2.y > p3.y) pmin3.x -= M;
                if (p2.x < p3.x || p2.y > p3.y) pmin3.y -= M;
                if (p2.x < p3.x || p2.y < p3.y) pmax3.x += M;
                if (p2.x > p3.x || p2.y < p3.y) pmax3.y += M;
            }
            else
            {
                if (p2.x < p3.x || p2.y > p3.y) pmin3.x -= M;
                if (p2.x < p3.x || p2.y < p3.y) pmin3.y -= M;
                if (p2.x > p3.x || p2.y < p3.y) pmax3.x += M;
                if (p2.x > p3.x || p2.y > p3.y) pmax3.y += M;
            }
            pmin = point(min(pmin2.x, pmin3.x), min(pmin2.y, pmin3.y));
            pmax = point(max(pmax2.x, pmax3.x), max(pmax2.y, pmax3.y));
            for (int j = 0; j < n; ++j)
            {
                point ps = p[j], pt = p[(j+1)%n];
                if (!( (ps.x == pt.x && (ps.x >= pmax.x || ps.x <= pmin.x || min(ps.y, pt.y) >= pmax.y || max(ps.y, pt.y) <= pmin.y)) 
                    || (ps.y == pt.y && (ps.y >= pmax.y || ps.y <= pmin.y || min(ps.x, pt.x) >= pmax.x || max(ps.x, pt.x) <= pmin.x)) ))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}

