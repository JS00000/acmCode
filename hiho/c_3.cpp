// underAC
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2007
using namespace std;

typedef long double dd;

const dd pi = acos(-1.0);
const dd eps = 1e-12;

int x[maxn], y[maxn], vx[maxn], vy[maxn];


int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, x0, y0, r, v0;
        scanf("%d%d%d%d%d", &n, &x0, &y0, &r, &v0);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d", x+i, y+i, vx+i, vy+i);
        }
        bool flag = 0;
        for (int j = -10000; j <= 10000; j++) {
            dd theta = pi*j/10000.0;
            dd vx0 = v0*cos(theta), vy0 = v0*sin(theta);
            bool possible = 1;
            for (int i = 0; i < n; i++) {
                dd a = (vx[i] - vx0)*(vx[i] - vx0) + (vy[i] - vy0)*(vy[i] - vy0);
                dd b = 2*(vx[i] - vx0)*(x[i] - x0) + 2*(vy[i] - vy0)*(y[i] - y0);
                dd c = (x[i] - x0)*(x[i] - x0) + (y[i] - y0)*(y[i] - y0) - r*r;
                dd delta = b*b - 4*a*c;
                if (delta > -eps) {
                    if (c < eps) {
                        possible = 0;
                        break;
                    } else {
                        if (b < eps) {
                            possible = 0;
                            break;
                        }
                    }
                }
            }
            if (possible) {
                flag = 1;
                break;
            }
        }
        if (flag) printf("Raucdly\n");
        else printf("Ygpkpk\n");
    }
    return 0;
}
