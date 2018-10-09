#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

int gcd(int a, int b)
{
    return b==0?a:gcd(b, a%b);
}

int abs(int x)
{
    return x < 0 ? -x : x;
}

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
    bool operator< (const point& r) const
    {
        return x == r.x ? y < r.y : x < r.x;
    }
};

unsigned long line_number(int n, int tx, int ty, point v[])
{
    for (int i = 0; i < n; i++) {
        v[i].x -= tx;
        v[i].y -= ty;
    }
    set<point> s;
    for (int i = 0; i < n; i++) {
        if (v[i].x < 0) v[i].x = -v[i].x, v[i].y = -v[i].y;
        int g = gcd(v[i].x, abs(v[i].y));
        s.insert( point(v[i].x/g, v[i].y/g) );
    }
    return s.size();
}

int n, tx, ty;
point v[1000];

int main()
{
    scanf("%d%d%d", &n, &tx, &ty);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &v[i].x, &v[i].y);
    }
    printf("%lu\n", line_number(n, tx, ty, v));
    return 0;
}
