#include <cstdio>
#define maxn 1007

int n;
int a[maxn];

void fun(int l, int r)
{
    int k = l;
    for (int i = l+1; i < r; i++)
        if (a[i] < a[k]) k = i;
    printf("%d ", a[k]);
    if (l < k) fun(l, k);
    if (k+1 < r) fun(k+1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    fun(0, n);
    return 0;
}
