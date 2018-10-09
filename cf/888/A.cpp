#include <cstdio>
#include <algorithm>
#define maxn 1007
using namespace std;

int n, a[maxn];


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);
    int ans = 0;
    for (int i = 1; i < n-1; i++)
        if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1]))
            ans++;
    printf("%d\n", ans);
    return 0;
}
