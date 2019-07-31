#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    int t;
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        sum += t;
        ans += abs(sum);
    }
    printf("%lld\n", ans);
    return 0;
}
