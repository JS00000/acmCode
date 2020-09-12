#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define maxn 1007
using namespace std;

const double eps = 1e-4;

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

point p[20];


int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 20; i++) {
            p[i].input();
        }
        int j = 0;
        for (int i = 0; i < 20; i++) {
            if ( fabs(dist(p[i], p[(i + 1) % 20]) - 9) < eps ) j = i;
        }
        if ( fabs(dist(p[(j + 1) % 20], p[(j + 2) % 20]) - 8) < eps ) {
            if ( det(p[(j + 1) % 20] - p[j], p[(j + 2) % 20] - p[(j + 1) % 20]) > 0) printf("right\n");
            else printf("left\n");
        } else {
            if ( det(p[(j + 1) % 20] - p[j], p[j] - p[(j + 19) % 20]) > 0) printf("right\n");
            else printf("left\n");
        } 
    }
    return 0;
}

