#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

int n, m, l;
int a[maxn], b[maxn], c[maxn];

int abs(int x)
{
    return x<0?-x:x;
}

int dis(int i, int j, int k)
{
    return abs(a[i]-b[j])+abs(a[i]-c[k])+abs(b[j]-c[k]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    for (int i = 0; i < m; i++) scanf("%d", b+i);
    for (int i = 0; i < l; i++) scanf("%d", c+i);
    sort(a, a+n);
    sort(b, b+m);
    sort(c, c+l);
    int i, j, k;
    int ans = dis(0,0,0);
    for (i = j = k = 0; i < n; ++i)
    {
        while(b[j+1] < a[i] && j < m-1) j++;
        while(c[k+1] < a[i] && k < l-1) k++;
        ans = min(ans, dis(i, j, k));
        if (k+1<l) ans = min(ans, dis(i, j, k+1));
        if (j+1<m) ans = min(ans, dis(i, j+1, k));
        if (k+1<l && j+1<m) ans = min(ans, dis(i, j+1, k+1));
    }
    printf("%d\n", ans);
    return 0;
}
