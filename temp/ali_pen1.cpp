#include <cstdio>

int main()
{
    int n;
    double ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        ans += 1.0/i;
    printf("%f\n", ans*n);
    return 0;
}
