#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2007
using namespace std;

const double PI = acos(-1.0);

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
    double norm() {
        return x * x + y * y;
    }
    double dist() {
        return sqrt(norm());
    }
};

point p[maxn];
struct node
{
    double angle;
    bool type;
    int id;
    node(){};
    node(double _angle, bool _type, int _id) {
        angle = _angle;
        type = _type;
        id = _id;
    }
}q[maxn*2];
bool flag[maxn];

bool cmp(node a, node b) {
    return a.angle == b.angle ? a.type < b.type : a.angle < b.angle;
}

double fit(double a) {
    while (a < 0) a += 2 * PI;
    while (a >= 2 * PI) a -= 2 * PI;
    return a;
}

int main()
{
    int n;
    double r;
    scanf("%d%lf", &n, &r);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (p[i].x == p[j].x && p[i].y == p[j].y) {
                    q[k++] = node(0, 0, j);
                    q[k++] = node(2 * PI, 1, j);
                } else {
                    point diff = p[j] - p[i];
                    double d = diff.dist();
                    if (d <= r * 2) {
                        double a = atan2(diff.y, diff.x);
                        double b = acos(d / 2 / r);
                        q[k++] = node(fit(a-b), 0, j);
                        q[k++] = node(fit(a+b), 1, j);
                    }
                }

            }
            flag[j] = 0;
        }
        sort(q, q+k, cmp);
        int cnt = 0;
        for (int j = 0; j < k; j++) {
            if (!q[j].type)  {
                cnt++;
                flag[q[j].id] = 1; 
                ans = max(ans, cnt);
            } else if (flag[q[j].id]) {
                cnt--;
                flag[q[j].id] = 0;
            }
        }
        for (int j = 0; j < k; j++) {
            if (!q[j].type)  {
                cnt++;
                flag[q[j].id] = 1; 
                ans = max(ans, cnt);
            } else if (flag[q[j].id]) {
                cnt--;
                flag[q[j].id] = 0;
            }
        }
    }
    printf("%d\n", ans + 1);
    return 0;
}
