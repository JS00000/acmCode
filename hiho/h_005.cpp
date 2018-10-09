#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int a[maxn][maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            scanf("%d", &a[i][j]);
    for (int i = n-2; i >= 0; --i)
        for (int j = 0; j <= i; ++j)
            a[i][j] += max(a[i+1][j], a[i+1][j+1]);
    printf("%d\n", a[0][0]);
    return 0;
}
