#include <cmath>
#include <cstdio>
#include <algorithm>
#define maxn 1007
using namespace std;

typedef long long ll;

// m is small
ll c(int n, int m)
{
    ll ret = 1;
    for (int i = n; i > n-m; i--)
        ret *= i;
    for (int i = m; i > 0; i--)
        ret /= i;
    return ret;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if (k == 1) {
        printf("1\n");
    } else if (k == 2) {
        printf("%I64d\n", c(n, 2) + 1);
    } else if (k == 3) {
        printf("%I64d\n", c(n, 3) * 2 + c(n, 2) + 1);
    } else if (k == 4) {
        printf("%I64d\n", c(n, 4) * 9 + c(n, 3) * 2 + c(n, 2) + 1);
    }
    return 0;
}
