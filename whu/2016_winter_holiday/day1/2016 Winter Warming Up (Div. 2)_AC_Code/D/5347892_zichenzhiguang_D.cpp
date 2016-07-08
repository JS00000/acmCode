#include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    int ans;
    if(n <= 4 || n % 2) ans = 0;
    else {
        n /= 2;
        if(n % 2) ans = n / 2;
        else ans = n / 2 - 1;
    }
    printf("%d\n", ans);
    return 0;
}
