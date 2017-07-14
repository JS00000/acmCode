#include <cstdio>
#define maxn 107
#define mod 1000000007
typedef unsigned long long llu;
using namespace std;

int f[maxn][2];

int main()
{

    int n;
    scanf("%d", &n);
    llu ans = 1;
    for (int i = 0; i < n; i++) ans = (ans * 2) % mod;
    f[1][0] = 1;
    f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i][0] = (f[i-1][0] + f[i-1][1]) % mod;
        f[i][1] = f[i-1][0] % mod;
    }
    ans = (ans  + mod - f[n][0] + mod - f[n][1]) % mod;
    printf("%llu\n", ans);
    return 0;
}
