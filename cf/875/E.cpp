#include <cstdio>
#include <algorithm>
#define maxn 100007
using namespace std;

int a[maxn], n, s1, s2;

bool check(int x)
{
    int L = a[n-1] - x;
    int R = a[n-1] + x;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= L && a[i] <= R) {
            L = a[i] - x;
            R = a[i] + x;
        } else {
            L = max(L, a[i] - x);
            R = min(R, a[i] + x);
        }
    }
    return (s1 >= L && s1 <= R) || (s2 >= L && s2 <= R);
}

int main()
{
    scanf("%d%d%d", &n, &s1, &s2);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    int l = s1 - s2 > 0 ? s1 - s2: s2 - s1, r = 1000000009, mid;
    while (l <= r){
        mid = (l+r)>>1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
