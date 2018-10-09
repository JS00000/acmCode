#include <cmath>
#include <cstdio>

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

int main(int argc, char const *argv[])
{
    
    return 0;
}
