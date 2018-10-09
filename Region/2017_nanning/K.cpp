#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

int cmp(double x)
{
    if (fabs(x)<eps) return 0;
    if (x>0) return 1;
    return -1;
}

struct point
{
    double x,y;
    point(){}
    point(double a, double b) : x(a), y(b) {}
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
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
point rotate_point(const point &p, double A)
{
    double tx = p.x, ty = p.y;
    return point(tx*cos(A) - ty*sin(A), tx*sin(A) + ty*cos(A));
}

struct line
{
    point a,b;
    line(){}
    line(point x, point y) : a(x), b(y){}
};
double dis_point_segment(const point &p, const point &s, const point &t)
{
    if (cmp(dot(p-s,t-s))<0) return (p-s).norm();
    if (cmp(dot(p-t,s-t))<0) return (p-t).norm();
    return fabs(det(s-p,t-p)/dist(s,t));
}
void point_proj_line(const point &p, const point &s, const point &t, point &cp)
{
    double r=dot((t-s),(p-s)/dot(t-s,t-s));
    cp=s+r*(t-s);
}
bool point_on_segment(const point &p, const point &s, const point &t)
{
    return cmp(det(p-s,t-s))==0 && cmp(dot(p-s,p-t))<=0;
}
bool parallel(const line &a,const line &b)
{
    return !cmp(det(a.a-a.b,b.a-b.b));
}
bool line_make_point(const line &a, const line &b, point &res)
{
    if (parallel(a,b)) return false;
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    cout << s1 << " " << s2 << endl;
    res = (s1*a.b-s2*a.a)/(s1-s2);
    return true;
}
line move_d(const line &a, const double &len)
{
    point d=a.b-a.a;
    d=d/d.norm();
    d=rotate_point(d,PI/2);
    return line(a.a+d*len, a.b+d*len);
}
int xyCmp(const double p, const double mini, const double maxi)
{
    return cmp(p-mini)*cmp(p-maxi);
}
int betweenCmp(const point &a, const point &b, const point &c)
{
    if (fabs(b.x-c.x)>fabs(b.y-c.y))
    {
        return xyCmp(a.x, min(b.x,c.x), max(b.x,c.x));
    }
    else
    {
        return xyCmp(a.y, min(b.y,c.y), max(b.y,c.y));
    }
}
double cross(const point &a, const point &b, const point &c)
{
    return det(point(b.x-a.x, b.y-a.y), point(c.x-a.x, c.y-a.y));
}
int segCross(const line &l, const line &m)
{
    double s1,s2,s3,s4;
    int d1,d2,d3,d4;
    d1 = cmp(s1=cross(l.a,l.b,m.a));
    d2 = cmp(s2=cross(l.a,l.b,m.b));
    d3 = cmp(s3=cross(m.a,m.b,l.a));
    d4 = cmp(s4=cross(m.a,m.b,l.b));
    if ((d1^d2)==-2 && ((d3^d4)==-2))
    {
        return 1;
    }
    if ((d1==0 && betweenCmp(m.a, l.a, l.b)<=0)||
        (d2==0 && betweenCmp(m.b, l.a, l.b)<=0)||
        (d3==0 && betweenCmp(l.a, m.a, m.b)<=0)||
        (d4==0 && betweenCmp(l.b, m.a, m.b)<=0))
        return 2;
    return 0;
}

int main()
{
    int minx1, miny1, minx2, miny2, maxx1, maxy1, maxx2, maxy2;
    scanf("%d%d%d%d", &minx1, &miny1, &maxx1, &maxy1);
    scanf("%d%d%d%d", &minx2, &miny2, &maxx2, &maxy2);
    while (!scanf("%d%d%d%d", &tx1, &ty1, &tx2, &ty2)) {
        
    }
    return 0;
}
