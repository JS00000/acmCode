#include <cstdio>
#define maxn 100007

int n, a[maxn];
int ql[maxn], qr[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    int p = 1;
    int ans = n;
    for (int i = 1; i < n; i++) 
        if (a[i] > a[i + 1]) p = 0;
    if (p) {
        printf("%d\n", 0);
    } else {
        int iql = 1, iqr = n;
        ql[0] = -1;
        qr[n+1] = 100000001;
        for (int i = 1; i <= n; i++) {
            while (iql > 0 && ql[iql-1] > a[i]) iql--;
            ql[iql++] = a[i];
        }
        int t = 0;
        for (int i = 1; i <= n; i++) 
            if (ql[i] != a[i]) {
                t = i;
                break;
            }
        ans -= (t - 1);
        for (int i = n; i >= 1; i--) {
            while (iqr <= n && qr[iqr+1] < a[i]) iqr++;
            qr[iqr--] = a[i];
        }
        t = 0;
        for (int i = n; i > 0; i--) 
            if (qr[i] != a[i]) {
                t = i;
                break;
            }
        ans -= (n - t);
        printf("%d\n", ans);
    }
    return 0;
}
