#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
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
    double norm2()
    {
        return x*x+y*y;
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
double dist2(const point &a, const point &b)
{
    return (a - b).norm2();
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n = 10, m = 20;
    point p1[n];
    point p2[m];
    for (int i = 0; i < n; i++) {
        p1[i] = point(rand() % 10000, rand() % 10000);
    }
    for (int i = 0; i < m; i++) {
        p2[i] = point(rand() % 10000, rand() % 10000);
    }

    // #1 sum up
    double sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += dist2(p1[i], p2[j]);
        }
    }
    printf("%f\n", sum / n / m);

    // #2 n to 1
    point g1(0,0);
    double d = 0;
    for (int i = 0; i < n; i++) {
        g1 = g1 + p1[i];
        d += p1[i].norm2();
    }
    g1 = g1 / n;
    d /= n;
    d -= g1.norm2();
    sum = 0;
    for (int j = 0; j < m; j++) {
        sum += dist2(g1, p2[j]);
    }
    printf("%f\n", sum / m + d);

    // #3 n to m
    point s1(0,0), s2(0,0);
    double ss1 = 0, ss2 = 0;
    for (int i = 0; i < n; i++) {
        s1 = s1 + p1[i];
        ss1 += p1[i].norm2();
    }
    ss1 /= n;
    for (int i = 0; i < m; i++) {
        s2 = s2 + p2[i];
        ss2 += p2[i].norm2();
    }
    ss2 /= m;
    printf("%f\n", ss1 + ss2 - 2 * dot(s1, s2) / n / m);

    // the answer is same
    return 0;
}
