#include <cstdio>
#define maxn 1007
#define mod 1000000007
using namespace std;

int a[1007][1007];

int main()
{
    for (int i = 0; i <= 1000; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            a[i][j] = (a[i-1][j-1] + a[i-1][j]) % mod;
        }
    }
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        if (m < n) {
            int t = m;
            m = n;
            n = t;
        }
        if (m - n < n) n = m - n;
        printf("%d\n", a[m][n]);
    }
    return 0;
}
