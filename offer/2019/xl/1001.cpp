#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 10007
using namespace std;

long long a[maxn];

int main()
{
    long long j = 0, k, x;
    char c;
    while (1) {
        scanf("%lld%c", a+j++, &c);
        if (c == '\n')
            break;
    };
    scanf("%lld", &k);
    scanf("%lld", &x);
    long long n = j;
    long long l = 0, r = n-1, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (a[mid] >= x) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    r = l+1;
    // printf("%lld %lld\n", l, r);
    j = k;
    while (j) {
        if (l == -1) {
            r++;
        } else if (r == n) {
            l--;
        } else if (x - a[l] <= a[r] - x) {
            l--;
        } else {
            r++;
        }
        j--;
    }
    for (long long i = l+1; i < r-1; i++)
        printf("%lld,", a[i]);
    if (k >= 1)
        printf("%lld\n", a[r-1]);
    return 0;
}
