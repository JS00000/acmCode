#include <cstdio>
#include <algorithm>
using namespace std;

int a[3];

int main()
{
    scanf("%d%d%d", a, a+1, a+2);
    sort(a, a+3);
    if (a[2] == a[1] && a[2] == a[0] && a[2] == 0) {
        printf("0\n");
    } else if (a[2] <= a[1] + a[0]) {
        printf("%d\n", ((a[2] + a[1] + a[0] - 1) / 20 + 1) * 6);
    } else {
        int ans = (a[0] + a[1]) / 10;
        a[2] -= ans * 10;
        int k = a[0] + a[1] - ans * 10;
        if (k < 8) {
            a[2] -= (15 - k);
        } else {
            a[2] -= k;
        }
        ans++;
        if (a[2] > 0) ans += (a[2] - 1) / 15 + 1;
        printf("%d\n", ans * 6);
    }
    return 0;
}
