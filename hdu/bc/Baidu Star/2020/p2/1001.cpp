#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n, m, p;
        scanf("%lld%lld%lld", &n, &m, &p);
        if (n >= m) printf("%lld\n", (n - m) / ( (m - m * (100 - p) / 100) ) + 1);
        else printf("0\n");
    }
    return 0;
}
