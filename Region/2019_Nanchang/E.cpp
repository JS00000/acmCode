#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int main()
{
    int T, n, m, q, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 0; i < q; i++) {
            scanf("%d", &k);
            int t = n, l = k-1, cnt = 0;
            while (1) {
                if ( l % (m+1) == 0 ) {
                    cnt += l/(m+1) + 1;
                    break;
                } else if (t < 30) {
                    int id[31];
                    for (int ii = 0; ii < t; ii++) {
                        id[ii] = 0;
                    }
                    int j = 0;
                    int cn = 1;
                    id[j] = cn;
                    while (!id[l]) {
                        int c = 0;
                        while (c < m) {
                            if (id[j] == 0) c++;
                            j = (j+1) % t;
                        }
                        while (id[j]) j = (j+1) % t;
                        id[j] = ++cn;
                    }
                    cnt += id[l];
                    break;
                } else {
                    int c = t/(m+1);
                    cnt += c;
                    t -= c;
                    l = (l + t%(m+1) - 1) % t;
                }
            }
            printf("%d\n", cnt);
        }
    }
    return 0;
}
