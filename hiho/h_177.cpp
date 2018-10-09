#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 110
using namespace std;

int n, m;
int h[maxn], l[maxn], r[maxn], w[maxn];

int cal(int x1, int y1, int x2, int y2)
{
    if (x1 > x2 || y1 > y2) return 0;
    int ret;
    if (x1 <= 0 && 0 <= x2 && y1 <= 0 && 0 <= y2) ret = 1;
    else ret = 0;
    for (int i = 2; i < n; i++) {
        if (x1 <= r[i] && r[i] <= x2 && !(y1 > r[i] || y2 < l[i])) {
            ret += (1<<(i-1));
            if (y1 > l[i]) {
                ret -= (y1 - l[i] - 1) / w[i] + 1;
            }
            if (y2 < r[i]){
                ret -= (r[i] - y2 - 1) / w[i] + 1;
            }
        }
    }
    if (n > 1 && x1 <= r[n] && r[n] <= x2 && !(y1 > r[n] || y2 < l[n])) {
        ret += (1<<(n-1));
        if (y1 > l[n]) {
            ret -= (y1 - l[n] - 1) / 3 + 1 - ((y1 - l[n]) % 6 == 4);
        }
        if (y2 < r[n]){
            ret -= (r[n] - y2 - 1) / 3 + 1 - ((r[n] - y2) % 6 == 4);
        }
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    h[n] = 0;
    h[n-1] = 2;
    for (int i = n-2; i > 0; i--) {
        h[i] = h[i+1] * 2 + 1;
    }
    l[1] = 0;
    r[1] = 0;
    for (int i = 2; i <= n; i++) {
        l[i] = l[i-1] - (h[i-1] - h[i]);
        r[i]=  -l[i];
    }
    for (int i = 2; i < n; i++) {
        w[i] = h[i-1] + 1;
    }
    for (int k = 0; k < m; k++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", cal(x1, y1, x2, y2));
    }
    return 0;
}
