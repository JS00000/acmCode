#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200007
using namespace std;

const int mod = 1000000007;
int n, s, S;
int a[maxn], f[2][maxn];

int main()
{
    scanf("%d%d", &n, &s);
    S = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        S += a[i];
    }
    for (int i = 0; i < maxn; i++)
        f[0][i] = 0, f[1][i] = 0;
    f[0][S] = 1;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= S*2; j++) {
            f[k^1][j] = 0;
            if (j-a[i] >= 0) {
                f[k^1][j] = f[k][j-a[i]];
            }
            if (j+a[i] <= S*2) {
                f[k^1][j] = (f[k^1][j] + f[k][j+a[i]]) % mod;
            }
        }
        k = k^1;
    }
    printf("%d\n", f[k][S+s]);
    return 0;
}
