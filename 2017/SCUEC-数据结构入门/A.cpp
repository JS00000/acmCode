#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 5007
using namespace std;

int main()
{
    int a[maxn];
    int T, n, i, k, p;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) a[i] = i;
        k = n, p = 1;
        while(k > 3)
        {
            if (p) for (i = 1, k = (k+1)/2; i <= k; ++i) a[i] = a[i*2-1];
            else for (i = 1, k = (k+1)*2/3; i <= k; ++i) a[i] = a[(i+1)*3/2-2];
            p ^= 1;
        }
        for (int i = 1; i < k; ++i)
            printf("%d ", a[i]);
        printf("%d\n", a[k]);
    }
    return 0;
}
