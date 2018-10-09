#include <cmath>
#include <iostream>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 8009;

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

struct polygon
{
    int n;
    point a[maxn];
    polygon(){}
    double area()
    {
        double sum = 0;
        a[n] = a[0];
        for (int i = 0; i < n; ++i) sum+=det(a[i+1],a[i]);
        return sum/2;
    }
    double fxy()
    {
        point ans(0,0);
        int flag = cmp(area());
        if (flag==0) return 0;
        a[n] = a[0];
        for (int i = 0; i < n; ++i) ans=ans+(a[i]+a[i+1])*det(a[i+1],a[i]);
        return (ans.x + ans.y)/6.*flag;
    }
};

polygon pol;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &pol.n);
        for (int i = 0; i < pol.n; i++) 
            scanf("%lf%lf", &pol.a[i].x, &pol.a[i].y);
        printf("%.2f\n", pol.fxy()+eps);
    }
    return 0;
}
