#include <stdio.h>

int B, N;
int s[101], c[101];
int f[1001], idx[1001];
int nex[101][1001];

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &B, &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d%d", s+i, c+i);
        }
        for (int i = 0; i <= B; i++) 
            f[i] = 0, idx[i] = 0;
        for (int i = 0; i <= N; i++) 
            for (int j = 0; j <= B; j++) 
                nex[i][j] = 0;
        bool flag = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = B; j >= 0; j--) 
                if (j - c[i] >= 0) {
                    if (f[j - c[i]] + s[i] > f[j]) {
                        flag = 1;
                        f[j] = f[j - c[i]] + s[i];
                        nex[i][j] = idx[j - c[i]];
                        idx[j] = i;
                    }
                }
                else break;
        }
        int cost = 0, score = 0;
        for (int i = B; i >= 0; i--) 
            if (f[i] > score) {
                score = f[i];
                cost = i;
            }
        printf("Case #%d:\n", ++kase);
        if (flag) {
            int st[101], ist = 0, k = idx[cost], true_cost = 0;
            while (k) {
                st[ist++] = k;
                int tk = k;
                k = nex[k][cost];
                cost -= c[tk];
                true_cost += c[tk];
            }
            printf("%d %d\n", score, true_cost);
            printf("%d", st[--ist]);
            while(ist) printf(" %d", st[--ist]);
            printf("\n");
        } else {
            printf("0 0\n");
        }
    }
    return 0;
}
