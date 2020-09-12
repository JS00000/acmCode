#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
 
const double eps=1e-8;
const double inf=1e9;
const int MAXN=210;
const double PI = acos(-1.0);

int n;
double r;
int cCnt,curCnt;
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
    double norm()
    {
        return sqrt(x*x+y*y);
    }
};
point points[MAXN],p[MAXN],q[MAXN];
void getline(point &x,point &y,double &a,double &b,double &c)
{
    a = y.y - x.y;
    b = x.x - y.x;
    c = y.x * x.y - x.x * y.y;
}
void initial()
{
    for(int i = 1; i <= n; ++i)p[i] = points[i];
    p[n+1] = p[1];
    p[0] = p[n];
    cCnt = n;
}
double det(const point &a, const point &b)
{
    return a.x*b.y-a.y*b.x;
}
point intersect(point &x, point &y, double a, double b, double c)
{
    double u = fabs(a * x.x + b * x.y + c);
    double v = fabs(a * y.x + b * y.y + c);
    point pt;
    pt.x=(x.x * v + y.x * u) / (u + v);
    pt.y=(x.y * v + y.y * u) / (u + v);
    return pt;
}
void cut(double a, double b, double c)
{
    curCnt = 0;
    for(int i = 1; i <= cCnt; ++i)
    {
        if(a*p[i].x + b*p[i].y + c >= 0) q[++curCnt] = p[i];
        else
        {
            if(a*p[i-1].x + b*p[i-1].y + c > 0)
            {
                q[++curCnt] = intersect(p[i],p[i-1],a,b,c);
            }
            if(a*p[i+1].x + b*p[i+1].y + c > 0)
            {
                q[++curCnt] = intersect(p[i],p[i+1],a,b,c);
            }
        }
    }
    for(int i = 1; i <= curCnt; ++i)p[i] = q[i];
    p[curCnt+1] = q[1];
    p[0] = p[curCnt];
    cCnt = curCnt;
}
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
void solve()
{
    initial();
    for(int i = 1; i <= n; ++i){
        point ta, tb, tt;
        tt.x = points[i+1].y - points[i].y;
        tt.y = points[i].x - points[i+1].x;
        double k = r / sqrt(tt.x * tt.x + tt.y * tt.y);
        tt.x = tt.x * k;
        tt.y = tt.y * k;
        ta.x = points[i].x + tt.x;
        ta.y = points[i].y + tt.y;
        tb.x = points[i+1].x + tt.x;
        tb.y = points[i+1].y + tt.y;
        double a,b,c;
        getline(ta,tb,a,b,c);
        cut(a,b,c);
    }
}

void inOrder(){
    for(int i = 1; i < (n+1)/2; i ++)
        swap(points[i], points[n-i]);
}

double perimeter(point pt[], int m)
{
    double sum=0;
    pt[m] = pt[0];
    for (int i = 0; i < m; ++i)
        sum+=(pt[i+1]-pt[i]).norm();
    return sum;
}

double area(point pt[], int m)
{
    double sum = 0;
    pt[m] = pt[0];
    for (int i = 0; i < m; ++i) sum+=det(pt[i+1],pt[i]);
    return sum/2;
}

int main()
{
    int nCase;
    scanf("%d", &nCase);
    while (nCase--){
        int A, B;
        scanf("%d%lf", &n, &r);
        scanf("%d%d", &A, &B);
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&points[i].x,&points[i].y);
        if (det(points[2] - points[1], points[3] - points[2]) > 0) {
            inOrder();
        }
        points[n+1]=points[1];
        points[0]=points[n];
        if (A <= B) {
            printf("%.12lf\n", A * area(points, n));
        } else {
            solve();
            if (cCnt <= 0) {
                printf("%.12lf\n", A * area(points, n));
            } else {
                double area_A, area_B;
                area_B = r * r * PI + r * perimeter(p, cCnt) + area(p, cCnt);
                area_A = area(points, n) - area_B;
                printf("%.12lf\n", area_A * A + area_B * B);
            }
        }

    }
    return 0;
}
