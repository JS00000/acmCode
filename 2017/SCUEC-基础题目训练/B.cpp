#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define maxn 10007

int n;
int a[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", a+i);
        std::sort(a, a+n);
        int mid = a[n/2];
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += abs(a[i] - mid);
        printf("%d\n", sum);
    }
    return 0;
}
