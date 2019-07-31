#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;



int main()
{
    for (int n = 1; n < 100; n++) {
        int ans1 = n*(n+1)*(n+2)*(n+3)/24;
        int ans2 = 0;
        int t = 0, k = n;
        for (int i = 1; i <= n; i++) {
            t += i;
            ans2 += t * k;
            k--;
        }
        printf("%d %d\n", ans1, ans2);
        if (ans1 != ans2) printf("bug! %d\n", n);
    }
    return 0;
}
