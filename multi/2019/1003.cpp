#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

bool p[maxn];
long long n, k;
long long f[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        if (n+1>=2*k && (n*(n+1))%(2*k)==0) {
            printf("yes\n");
            for (int i = 1; i <= n; i++) {
                p[i] = 0;
                f[i] = (n*(n+1))/(2*k);
            }
            int last = n;
            for (int j = 0; j < k; j++) {
                while (f[j]) {
                    if (!p[last]) {
                        if (f[j] >= last) {
                            f[j] -= last;
                            p[last] = 1;
                            last--;
                            printf("%d ", last);
                        }
                    } else {
                        last--;
                    }
                }
                printf("\n");
            }
        } else {
            printf("no\n");
        }
    }
    return 0;
}
