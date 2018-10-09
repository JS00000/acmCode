#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
point p[109];

int cmp(int x)
{
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
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
};
double det(const point &a, const point &b)
{
    return a.x*b.y-a.y*b.x;
}

struct node
{
    int a, d;
};

int cccmp(node a, node b)
{
    return a.a < b.a;
}

void cmp3(int a0, int a1, int a2, int &minp, int &maxp)
{
    node cc[3];
    cc[0].a = a0, cc[0].d = 0;
    cc[1].a = a1, cc[1].d = 1;
    cc[2].a = a2, cc[2].d = 2;
    sort(cc, cc+3, cccmp);
    minp = cc[0].d, maxp = cc[2].d;
}

void cmp4(int a0, int a1, int a2, int a3, int &minp, int &maxp)
{
    node cc[4];
    cc[0].a = a0, cc[0].d = 0;
    cc[1].a = a1, cc[1].d = 1;
    cc[2].a = a2, cc[2].d = 2;
    cc[3].a = a2, cc[3].d = 3;
    sort(cc, cc+3, cccmp);
    minp = cc[0].d, maxp = cc[3].d;
}


int f4(point a0, point a1, point a2, point a3)
{
    if (cmp(det(a1 - a0, a2 - a0)) * cmp(det(a1 - a0, a3 - a0)) == -1) return 1;
    return 0;
}

int in_tr(point tr0, point tr1, point tr2, point a)
{
    int ptr[3];
    ptr[0] = cmp(det(tr0 - a, tr1 - tr0));
    ptr[1] = cmp(det(tr1 - a, tr2 - tr1));
    ptr[2] = cmp(det(tr2 - a, tr0 - tr2));
    return ptr[0] != 0 && ptr[0] == ptr[1] && ptr[0] == ptr[2];
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        int minp = -1, maxp = -1;
        if (n < 3) printf("NO\n");
        else if (n == 3) {
            if (det(p[1] - p[0], p[2] - p[0]) == 0) {
                printf("YES\n");
                if (p[0].x == p[1].x && p[0].x == p[2].x)
                    cmp3(p[0].y, p[1].y, p[2].y, minp, maxp);
                else 
                    cmp3(p[0].x, p[1].x, p[2].x, minp, maxp);
                for (int i = 0; i < n; i++) printf("%c", (i == minp || i == maxp) ? 'B': 'A');
                printf("\n");
            } else printf("NO\n");
        }
        else {
            printf("YES\n");
            if (in_tr(p[0], p[1], p[2], p[3]) ) {
                minp = maxp = 3;
            } else if (in_tr(p[0], p[1], p[3], p[2])) {
                minp = maxp = 2;
            } else if (in_tr(p[0], p[2], p[3], p[1])) {
                minp = maxp = 1;
            } else if (in_tr(p[1], p[2], p[3], p[0])) {
                minp = maxp = 0;
            } else {
                if (det(p[1] - p[0], p[2] - p[0]) == 0 && det(p[1] - p[0], p[3] - p[0]) == 0) {
                    if (p[0].x == p[1].x && p[0].x == p[2].x && p[0].x == p[3].x)
                        cmp4(p[0].y, p[1].y, p[2].y, p[3].y, minp, maxp);
                    else 
                        cmp4(p[0].x, p[1].x, p[2].x, p[3].x, minp, maxp);
                }
                else if (f4(p[0], p[1], p[2], p[3])) minp = 0, maxp = 1;
                else if (f4(p[0], p[2], p[1], p[3])) minp = 0, maxp = 2;
                else if (f4(p[0], p[3], p[1], p[2])) minp = 0, maxp = 3;
                else if (f4(p[1], p[2], p[0], p[3])) minp = 1, maxp = 2;
                else if (f4(p[1], p[3], p[0], p[2])) minp = 1, maxp = 3;
                else if (f4(p[2], p[3], p[0], p[1])) minp = 2, maxp = 3;
            }
            for (int i = 0; i < n; i++) printf("%c", (i == minp || i == maxp) ? 'B': 'A');
            printf("\n");
        }
    }
    return 0;
}
