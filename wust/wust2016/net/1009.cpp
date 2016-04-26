// 1583
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;
LL a[1000001];

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL n;
        scanf("%lld", &n);
        for (LL i = 0; i < n; ++i)
        {
            scanf("%lld", a+i);
        }
        LL i = 0, j = n-1;
        LL ans = 0;
        while(i < j)
        {
            ans = max(ans, (j-i)*min(a[i],a[j]));
            if (a[i] < a[j]) i++;
            else j--;
        }
        printf("%lld\n", ans);
    }
    return 0;
}