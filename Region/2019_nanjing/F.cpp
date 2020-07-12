#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#define maxn 100007
using namespace std;

int a[maxn];
int b[maxn];
int c[maxn];
int cnt[maxn];
int erase[maxn];
unordered_set<int> uset;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k, e;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &e);
            a[i] = e;
            b[e] = i;
            c[i] = 0;
            cnt[i] = 0;
        }
        if (k <= sqrt(n)) {
            for (int i = 2; i <= n; i++) {
                int l = max(1, b[i]-k);
                int r = min(n, b[i]+k);
                for (int j = l; j <= r; j++) {
                    if (c[i] < a[j] && a[j] < i) {
                        c[i] = a[j];
                    }
                }
            }
        } else {
            uset.clear();
            for (int i = n; i > 0; i--) {
                int erase_id = 0;
                for (std::unordered_set<int>::iterator j = uset.begin(); j != uset.end(); ++j) {
                    if (abs(b[i]-b[*j]) <= k) {
                        c[*j] = i;
                        erase[erase_id++] = *j;
                    }
                }
                for (int j = 0; j < erase_id; j++) {
                    uset.erase(erase[j]);
                }
                uset.insert(i);
            }
        }
        for (int i = 1; i < n; i++) {
            cnt[i] = cnt[c[i]] + 1;
            printf("%d ", cnt[i]);
        }
        printf("%d\n", cnt[c[n]]+1);
    }
    return 0;
}
