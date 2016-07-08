#include <bits/stdc++.h>

const int MAXN = 1001;

int n, m;
int a[MAXN], b[MAXN], s[MAXN*100];

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", b+i);
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= a[i]; ++j) {
                s[++cnt] = (2*j-1) * b [i];
            }
        }
        std::sort(s+1, s+1+cnt);
        printf("%lld\n", std::accumulate(s+1, s+1+m, 0ll));
    }
}
