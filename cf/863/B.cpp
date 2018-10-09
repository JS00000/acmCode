#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int n, N, a[maxn], ans;

int main()
{
    scanf("%d", &n);
    N = 2 * n;
    for (int i = 0; i < N; i++) {
        scanf("%d", a + i);
    }
    sort(a, a + N);
    ans = 0x7fffffff;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int diff = 0, s1 = 0, k = 1;
            while (k < n) {
                if (s1 == i) s1++;
                if (s1 == j) s1++;
                diff += a[s1 + 1] - a[s1];
                s1 += 2;
                k++;
            }
            ans = min(ans, diff);
        }
    }
    printf("%d\n", ans);
    return 0;
}
