#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int n;
int a[maxn];


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    int k;
    for (k = n-1; k > 0 && a[k] > a[k-1]; k--);
    if (k == 0)
        printf("1\n");
    else
    {
        for (int i = 0; i < k-1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[k-1]);
    }
    return 0;
}
