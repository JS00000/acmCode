#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

int a[maxn];
void exchange(int l, int r, int k)
{
    if (k == 1) return;
    int mid = (l + r) >> 1, lk, rk;
    rotate(a+l, a+l+r-mid, a+r);
    k--;
    if ((k >> 1) & 1) lk = rk = (k >> 1);
    else lk = (k >> 1) - 1, rk = (k >> 1) + 1;
    exchange(l, mid, lk);
    exchange(mid, r, rk);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if (k > n * 2 - 1 || (k & 1) == 0) printf("-1\n");
    else {
        for (int i = 0; i < n; i++) 
            a[i] = i;
        exchange(0, n, k);
        for (int i = 0; i < n - 1; i++) 
            printf("%d ", a[i] + 1);
        printf("%d\n", a[n - 1] + 1);
    }
    return 0;
}
