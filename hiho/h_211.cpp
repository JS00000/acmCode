#include <cstdio>

#define maxn 100007

int n, a[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    long long ans = 0;
    for (int j = 0; j < 32; j++) {
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] & 1) cnt++;
            a[i] >>= 1;
        }
        ans += cnt * (n - cnt);
    }
    printf("%lld\n", ans);
    return 0;
}
