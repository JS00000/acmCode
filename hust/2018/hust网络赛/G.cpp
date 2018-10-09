#include <cstdio>
#include <cmath>
#include <vector>
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
double det(const point &a, const point &b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(const point &a, const point &b)
{
    return a.x*b.x+a.y*b.y;
}
double dist(const point &a, const point &b)
{
    return (a - b).norm();
}

// 重心
point mass_center(point a, point b, point c)
{
    return (a+b+c)/3.;
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

// 垂心
point ortho_center(point a, point b, point c)
{
    return mass_center(a, b, c) * 3.0 - circum_center(a, b, c) * 2.0;
}

// 内心
point inner_center(point a, point b, point c)
{
    point cp;
    double la, lb, lc;
    la = (b-c).norm();
    lb = (c-a).norm();
    lc = (a-b).norm();
    cp.x = (la*a.x+lb*b.x+lc*c.x) / (la+lb+lc);
    cp.y = (la*a.y+lb*b.y+lc*c.y) / (la+lb+lc);
    return cp;
}

int main(int argc, char const *argv[])
{
    double ax, ay, bx, by, cx, cy, dx, dy;
    point a, b, c, d;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
    a = point(ax, ay);
    b = point(bx, by);
    c = point(cx, cy);
    d = point(dx, dy);
    if (dist(d, mass_center(a, b, c))   < eps || 
        dist(d, circum_center(a, b, c)) < eps || 
        dist(d, ortho_center(a, b, c))  < eps || 
        dist(d, inner_center(a, b, c))  < eps) 
        printf("Yes\n");
    else 
        printf("No\n");
    return 0;
}
