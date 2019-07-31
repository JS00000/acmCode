#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

int n, k;
long long a[maxn];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", a + i);
    }
    sort(a, a + n);
    int l = 0;
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        while (l < n && a[l] <= sum) l++;
        if (l >= n) printf("0\n");
        else {
            printf("%lld\n", a[l] - sum);
            sum += a[l] - sum;
        }
        l++;
    }
    return 0;
}
