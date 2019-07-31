#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int f[2][1024];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int R = (1 << m);
        for (int i = 0; i < R; i++) {
            f[0][i] = -1;
            f[1][i] = -1;
        }
        f[0][0] = 0;
        for (int i = 0; i < n; i++) {
            int v, s;
            scanf("%d%d", &v, &s);
            int attr = 0, ss;
            for (int j = 0; j < s; j++) {
                scanf("%d", &ss);
                attr |= (1 << (ss-1));
            }
            for (int j = 0; j < R; j++) {
                if (f[i%2][j] >= 0) {
                    f[(i+1)%2][j^attr] = max(f[i%2][j^attr], f[i%2][j] + v);
                } else {
                    f[(i+1)%2][j^attr] = f[i%2][j^attr];
                }
            }
        }
        printf("%d\n", f[n%2][R-1]);
    }
    return 0;
}
