// 计算几何点类
#include <set>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
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

int n;
point p[100007];

bool check(int id1, int id2, int id3)
{
    double x1 = p[id1].x, y1 = p[id1].y;
    double x2 = p[id2].x, y2 = p[id2].y;
    double x3 = p[id3].x, y3 = p[id3].y;
    if ((x1 - x2) * (y1 - y3) == (x1 - x3) * (y1 - y2)) return 0;
    double a = x1 - x2;
    double b = y1 - y2;
    double c = x1 - x3;
    double d = y1 - y3;
    double e = ((x1*x1 - x2*x2) - (y2*y2 - y1*y1))/2;
    double f = ((x1*x1 - x3*x3) - (y3*y3 - y1*y1))/2;
    double x0 = -(d*e - b*f) / (b*c - a*d);
    double y0 = -(a*f - c*e) / (b*c - a*d);
    double r2 = (x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0);
    if (fabs(x0) > 1e9 || fabs(y0) > 1e9) return 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt + n - i < (n + 1) / 2) return 0;
        if (cmp((p[i].x - x0)*(p[i].x - x0) + (p[i].y - y0)*(p[i].y - y0) - r2) == 0)
            cnt++;
    }
    // printf("de %d %d %d %d %f %f %f\n", id1, id2, id3, cnt, x0, y0, sqrt(r2));
    if (cnt >= (n + 1) / 2) {
        printf("%f %f %f\n", x0, y0, sqrt(r2));
        return 1;
    }
    return 0;
}

set<pair<int, pair<int, int> > > s;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        s.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            p[i].input();
        }
        if(n==1){
            printf("%f %f 0\n",p[0].x,p[0].y);
            continue;
        }
        if(n<=4){
            double x = (p[0].x + p[1].x)/2;
            double y = (p[0].y + p[1].y)/2;
            double r = sqrt((p[0].x - p[1].x)*(p[0].x - p[1].x) + (p[0].y - p[1].y)*(p[0].y - p[1].y))/2;
            printf("%f %f %f\n",x,y,r);
            continue;
        }
        srand((unsigned)time(NULL));
        while (1) {
            int id[3];
            id[0] = id[1] = id[2] = rand() % n;
            while (id[1] == id[0])
                id[1] = rand() % n;
            while (id[2] == id[0] || id[2] == id[1])
                id[2] = rand() % n;
            sort(id, id+3);
            if (s.find(make_pair(id[0], make_pair(id[1], id[2]))) != s.end()) continue;
            else s.insert(make_pair(id[0], make_pair(id[1], id[2])));
            if (check(id[0], id[1], id[2])) break;
        }
    }
    return 0;
}
