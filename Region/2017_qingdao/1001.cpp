// 四心
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1007;
const double eps = 1e-8;
const double PI = acos(-1.0);

int cmp(double x)
{
    return x < -eps ? -1 : x > eps ? 1 : 0;
}

struct point
{
    double x,y;
    point(){}
    point(double a, double b) : x(a), y(b) {}
    friend point operator+(const point &a, const point &b)
    {
        return point(a.x+b.x, a.y+b.y);
    }
    friend point operator-(const point &a, const point &b)
    {
        return point(a.x-b.x, a.y-b.y);
    }
    friend bool operator==(const point &a, const point &b)
    {
        return cmp(a.x-b.x) == 0 && cmp(a.y-b.y) == 0;
    }
    friend point operator*(const point &a, const double &b)
    {
        return point(a.x*b, a.y*b);
    }
    friend point operator*(const double &a, const point &b)
    {
        return point(a*b.x, a*b.y);
    }
    friend point operator/(const point &a, const double &b)
    {
        return point(a.x/b, a.y/b);
    }
    double norm()
    {
        return sqrt(x*x+y*y);
    }
};
double dist(const point &a, const point &b)
{
    return (a - b).norm();
}

// 外心
point circum_center(point a, point b, point c)
{
    point cp;
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1*a1 + b1*b1) / 2;
    double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2*a2 + b2*b2) / 2;
    double d = a1*b2 - a2*b1;
    cp.x = a.x + (c1*b2 - c2*b1) / d;
    cp.y = a.y + (a1*c2 - a2*c1) / d;
    return cp;
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    double ax, ay, bx, by, cx, cy;
    point a, b, c, ans;
    while(t--)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy);
        a = point(ax, ay);
        b = point(bx, by);
        c = point(cx, cy);
        ans = ortho_center(a, b, c);
        printf("%.4f %.4f\n", ans.x, ans.y);
    }
    return 0;
}
