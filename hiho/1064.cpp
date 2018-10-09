//Template
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <ios>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <functional>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdarg>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
#define pair(x, y) make_pair(x, y)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)

inline int read() {
    static int r, sign;
    static char c;
    r = 0, sign = 1;
    do c = getchar(); while (c != '-' && (c < '0' || c > '9'));
    if (c == '-') sign = -1, c = getchar();
    while (c >= '0' && c <= '9') r = r * 10 + (int)(c - '0'), c = getchar();
    return sign * r;
}

template <typename T>
inline void print(T *a, int n) {
    for (int i = 1; i < n; ++i) cout << a[i] << " ";
    cout << a[n] << endl;
}
#define PRINT(_l, _r, _s, _t) { cout << #_l #_s "~" #_t #_r ": "; for (int _i = _s; _i != _t; ++_i) cout << _l _i _r << " "; cout << endl; }

#define end End

const double eps = 1e-6, pi = 3.141592653589793238462643383279502884;

#define N 2000
struct point {
    double x, y;
    int w;
    inline void read() {
        scanf("%lf%lf%d", &x, &y, &w);
    }
} p[N + 1];
int n, k;

inline double sqr(double x) {
    return x * x;
}

inline double dist(const point &a, const point &b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

struct end {
    double x;
    bool l;
    int num;
    end() {}
    end(double _x, bool _l, int _n) {
        x = _x, l = _l, num = _n;
    }
    inline bool operator < (const end &p) const {
        if (x == p.x) return l > p.l;
        return x < p.x;
    }
} q[N << 2 | 1];
//double AT[N + 1][N + 1];

//bool check(double r) {
int check(double r) {
    double D = 4.0 * r * r;
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            double d = dist(p[i], p[j]);
            if (i == j || d - D > eps) continue;
//          double k = AT[i][j];
            double k = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
            double a = acos(sqrt((double)d) / (2.0 * r));
            double L = k - a, R = k + a;
            if (L < -pi || R > pi) {
                if (L < -pi) L += 2.0 * pi;
                if (R > pi) R -= 2.0 * pi;
                q[++cnt] = end(-pi, true, j);
                q[++cnt] = end(R, false, j);
                q[++cnt] = end(L, true, j);
                q[++cnt] = end(pi, false, j);
            } else {
                q[++cnt] = end(L, true, j);
                q[++cnt] = end(R, false, j);
            }
        }
        sort(q + 1, q + cnt + 1);
        
        int cover = p[i].w;
        ret = max(ret, cover);
        for (int j = 1; j <= cnt; ++j) {
            if (q[j].l) cover += p[q[j].num].w;
            else cover -= p[q[j].num].w;
/*          if (cover >= k - 1) {
//              cout << i << " " << r << endl;
                return true;
            }
            */
            ret = max(ret, cover);
        }
    }
//  return false;
    return ret;
}

int main(int argc, char *argv[]) {
#ifdef KANARI
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) p[i].read();
    /*
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                AT[i][j] = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
                */
    /*
    double l = 0.0, r = 7100.0, mid;
    while (r - l > eps) {
        mid = (l + r) / 2.0;
        if (check(mid)) r = mid;
        else l = mid;
    }
    */
    
    int ans = check(1.0);
    printf("%d\n", ans);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
