#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int a[39], b[1<<20];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    int half = n >> 1;
    for (int mask = 0; mask < (1 << half); mask++) {
        int sum = 0;
        for (int k = 0; k < half; k++) {
            if (mask & (1 << k)) sum = (sum + a[k]) % m;
        }
        b[mask] = sum;
    }
    sort(b, b + (1 << half));
    int ans = 0;
    for (int mask = 0; mask < (1 << (n - half)); mask++) {
        int sum = 0, add = 0;
        for (int k = 0; k < (n - half); k++) {
            if (mask & (1 << k)) sum = (sum + a[k + half]) % m;
        }
        int *p = lower_bound(b, b + (1 << half), m - sum);
        if (p != b) {
            add = *(p - 1);
        }
        ans = max(ans, sum + add);
    }
    printf("%d\n", ans);
    return 0;
}
