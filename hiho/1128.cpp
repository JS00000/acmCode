#include <cstdio>
int n, k, ans = 0;
int main()
{
    scanf("%d%d", &n, &k);
    int temp;
    bool flag = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &temp);
        if (temp == k) flag = 1;
        if (temp < k) ans++;
    }
    if (!flag) printf("-1\n");
    else printf("%d\n", ans+1);
    return 0;
}
