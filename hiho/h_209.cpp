#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0, t = 0;
    while (n) {
        if (n % 2) {
            t++;
        } else if (t > 0) {
            ans++;
            if (t > 1) t = 1;
            else t = 0;
        }
        n >>= 1;
    }
    if (t > 0) ans++;
    if (t > 1) ans++;
    printf("%d\n", ans);
    return 0;
}
