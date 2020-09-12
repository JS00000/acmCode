#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;
typedef long long ll;

ll a[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", a+i);
        sort(a+1, a+n+1);
        ll tot = 0;
        for (int i = 1; i <= n; i++) 
            tot += (i*2-1-n)*a[i];
        printf("%lld\n", tot);
    }
    return 0;
}
