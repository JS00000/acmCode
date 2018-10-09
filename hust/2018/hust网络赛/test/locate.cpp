#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int N, Q;

int main()
{
    freopen("1.in", "r", stdin);
    int T, kase;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        printf("Case #%d:\n", kase);
        scanf("%d%d", &N, &Q);
        int com, u, v, t = 0;
        for (int i = 0; i < Q; i++) {
            scanf("%d", &com);
            if (com == 1) {
                scanf("%d%d", &u, &v);
            } else if (com == 2) {
                scanf("%d", &u);
            } else if (com == 3) {
                scanf("%d", &u);
                t++;
            } else if (com == 4) {
                scanf("%d%d", &u, &v);
                t++;
            }
            if (t == 8467) {
                printf("%d\n", i+1);
            }
        }
    }
    return 0;
}
