#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

int main()
{
    int a[maxn], n, ma = 0, tot = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a+i);
        if (a[i] > ma) ma = a[i];
    }
    for (int i = 0; i < n; ++i)
        tot += ma - a[i];
    printf("%d\n", tot);
    return 0;
}
