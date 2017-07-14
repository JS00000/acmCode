#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

int a[maxn], b[maxn];
int n, s, t, temp;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", a+i);
        b[i] = a[i];
    }
    sort(b+1, b+n+1);
    s = n+1, t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] != a[i])
        {
            s = i;
            break;
        }
    }
    if (s == n+1) 
    {
        printf("0\n");
        return 0;
    }
    for (int i = n; i >= 1; i--)
    {
        if (b[i] != a[i])
        {
            t = i;
            break;
        }
    }
    printf("%d\n", t - s + 1);
    return 0;
}
