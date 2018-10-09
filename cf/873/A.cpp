#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;



int main()
{
    int n, k, x, temp, ans = 0;
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (i >= n - k) ans += x;
        else ans += temp;
    }
    printf("%d\n", ans);
    return 0;
}
