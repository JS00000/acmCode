#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 50007;

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

struct polygon_convex
{
    vector<point> P;
    polygon_convex(int Size=0)
    {
        P.resize(Size);
    }
};

bool comp_less(const point &a, const point &b)
{
    return cmp(a.x-b.x)<0 || (cmp(a.x-b.x)==0 && cmp(a.y-b.y)<0);
}

polygon_convex convex_hull(vector<point> &a)
{
    polygon_convex res(2*a.size()+5);
    sort(a.begin(),a.end(),comp_less);
    a.erase(unique(a.begin(),a.end()),a.end());
    int m=0;
    for (int i = 0; i < a.size(); ++i)
    {
        while(m>1 && cmp( res.P[m-2].y*res.P[m-1].x+res.P[m-1].y*a[i].x+a[i].y*res.P[m-2].x-res.P[m-2].y*a[i].x-res.P[m-1].y*res.P[m-2].x-a[i].y*res.P[m-1].x )<=0) --m;
        res.P[m++]=a[i];
    }
    int k=m;
    for (int i = int(a.size())-2; i >= 0; --i)
    {
        while(m>k && cmp( res.P[m-2].y*res.P[m-1].x+res.P[m-1].y*a[i].x+a[i].y*res.P[m-2].x-res.P[m-2].y*a[i].x-res.P[m-1].y*res.P[m-2].x-a[i].y*res.P[m-1].x )<=0) --m;
        res.P[m++]=a[i];
    }
    res.P.resize(m);
    if (a.size()>1) res.P.resize(m-1);
    return res;
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, pos, acc;
        std::vector<point> pt;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &pos, &acc);
            pt.push_back(point(acc, pos));
        }
        pt.push_back(point(0, -1e100));
        pt.push_back(point(-1e100, 0));
        polygon_convex pc = convex_hull(pt);
        printf("%ld\n", pc.P.size() - 2);
    }
    return 0;
}
