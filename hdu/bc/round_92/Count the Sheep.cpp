#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

int n, m, k;
int a[maxn], b[maxn];
pair<int, int> c[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; ++i) a[i] = 0;
        for (int i = 1; i <= m; ++i) b[i] = 0;
        int ta, tb;
        for (int i = 0; i < k; ++i)
        {
            scanf("%d%d", &ta, &tb);
            a[ta]++;
            b[tb]++;
            c[i] = make_pair(ta, tb);
        }
        long long ans = 0;
        for (int i = 0; i < k; ++i)
            ans += (a[c[i].first] - 1) * (b[c[i].second] - 1);
        ans *= 2;
        printf("%lld\n", ans);
    }
    return 0;
}
