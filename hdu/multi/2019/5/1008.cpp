#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-5;
const int maxn = 1007;

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
};
double det(const point &a, const point &b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(const point &a, const point &b)
{
    return a.x*b.x+a.y*b.y;
}
bool check(point &p, point &q, point &a, point &b)
{
    point mid = (a+b)/2;
    return cmp(det(mid-p,q-p))==0 && cmp(dot(b-a,q-p))==0;
}

point o[maxn];

int main()
{
    int n, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &o[i].x, &o[i].y);
        }
        int nh = n / 2;
        bool flag = 0;
        if (n < 5) flag = 1;
        if (n % 2) {
            // odd
            for (int i = 0; i < n; i++) {
                point p = o[i];
                point q = (o[(i + nh) % n] + o[(i + nh + 1) % n]) / 2;
                int change = 0;
                for (int j = 1; j <= nh; j++) {
                    if (!check(p, q, o[(i + j) % n], o[(i + j + (nh - j) * 2 + 1) % n]))
                        change++;
                }
                if (change <= 1) { 
                    flag = 1;
                    break;
                }
            }
        } else {
            // even
            for (int i = 0; i < nh; i++) {
                point p = o[i];
                point q = o[(i + nh) % n];
                int change = 0;
                for (int j = 1; j < nh; j++) {
                    if (!check(p, q, o[(i + j) % n], o[(i + j + (nh - j) * 2) % n]))
                        change++;
                }
                if (change <= 1) { 
                    flag = 1;
                    break;
                }
            }
            for (int i = 0; i < nh; i++) {
                point p = (o[i] + o[i + 1]) / 2;
                point q = (o[(i + nh) % n] + o[(i + nh + 1) % n]) / 2;
                int change = 0;
                for (int j = 1; j < nh; j++) {
                    if (!check(p, q, o[(i + j) % n], o[(i + j + (nh - j) * 2) % n]))
                        change++;
                }
                if (change <= 1) { 
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
