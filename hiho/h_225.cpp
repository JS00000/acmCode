// 凸多边形类
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100;
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
    friend point operator-(const point &a, const point &b) {
        return point(a.x-b.x, a.y-b.y);
    }
};

double det(const point &a, const point &b)
{
    return a.x*b.y-a.y*b.x;
}

// 返回1在内部，返回0在外部，返回-1在边界上
bool contain(const point tri[], const point &b)
{
    int sign=0;
    for (int i = 0; i < 3; ++i) {
        int x=cmp( det(tri[i]-b, tri[(i+1)%3]-b) );
        if (x) {
            if (sign) {
                if (sign!=x) {
                    return false;
                }
            } else {
                sign=x;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        point tri[3];
        point b;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &b.x, &b.y, &tri[0].x, &tri[0].y, &tri[1].x, &tri[1].y, &tri[2].x, &tri[2].y);
        if (contain(tri, b) == 0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
