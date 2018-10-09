#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct point
{
    int x, y;
    point(){};
    point(int a, int b): x(a), y(b){};
    point operator+(const point &b)
    {
        return point(x+b.x, y+b.y);
    }
    point operator-(const point &b)
    {
        return point(x-b.x, y-b.y);
    }
    bool operator==(const point &b)
    {
        return x == b.x && y == b.y;
    }
}p[4];

inline int dot(const point &a, const point &b)
{
    return (a.x * b.x + a.y * b.y);
}
inline int cross(const point &a, const point &b)
{
    return (a.x * b.y - a.y * b.x);
}

struct line
{
    point a, b;
    line(){};
    line(point x, point y): a(x), b(y){};
}l[4];

point f(point &a, point &b, point &c)
{
    return point( a.x + b.x - c.x , a.y + b.y - c.y);
}

int cnt[4];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 4; i++) {
            scanf("%d%d%d%d", &l[i].a.x, &l[i].a.y, &l[i].b.x, &l[i].b.y);
            cnt[i] = 0;
        }
        if (dot(l[0].a - l[0].b, l[1].a - l[1].b) == 0) {
            p[0] = l[0].a;
            p[1] = l[0].b;
            cnt[0]++;
            cnt[1]++;
            if (l[1].a == p[0]) {
                p[2] = l[1].b;
                p[3] = f(l[0].b, l[1].b, l[0].a);
                cnt[0]++;
            } else if (l[1].a == p[1]) {
                p[2] = l[1].b;
                p[3] = f(l[0].a, l[1].b, l[0].b);
                cnt[1]++;
            } else if (l[1].b == p[0]) {
                p[2] = l[1].a;
                p[3] = f(l[0].b, l[1].a, l[0].a);
                cnt[0]++;
            } else if (l[1].b == p[1]) {
                p[2] = l[1].a;
                p[3] = f(l[0].a, l[1].a, l[0].b);
                cnt[1]++;
            } else {
                printf("NO\n");
                continue;
            }
            cnt[2]++;
        } else if (cross(l[0].a - l[0].b, l[1].a - l[1].b) == 0) {
            if (dot(l[0].a - l[0].b, l[0].a - l[0].b) == dot(l[1].a - l[1].b, l[1].a - l[1].b)) {
                p[0] = l[0].a;
                p[1] = l[0].b;
                p[2] = l[1].a;
                p[3] = l[1].b;
                cnt[0]++;
                cnt[1]++;
                cnt[2]++;
                cnt[3]++;
            }
        } else {
            printf("NO\n");
            continue;
        }
        for (int i = 2; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (p[j] == l[i].a) cnt[j]++;
                if (p[j] == l[i].b) cnt[j]++;
            }
        }
        bool flag = 1;
        for (int i = 0; i < 4; i++) {
            if (cnt[i] != 2) flag = 0;
        }
        if (flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
