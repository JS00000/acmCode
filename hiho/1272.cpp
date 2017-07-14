#include <cstdio>
#define maxn 107

int n, a[maxn], b[maxn];

int main()
{
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        scanf("%d", &n);
        float temp;
        for (int i = 0; i < n; ++i)
        {
            scanf("%f%d", &temp, b+i);
            a[i] = int(temp*10+0.5);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] % 50 == 0)
                if (b[i] > ans) ans = b[i];
            for (int j = i+1; j < n; ++j)
            {
                if ((a[i] + a[j]) % 50 == 0)
                    if (b[i] + b[j] > ans) ans = b[i] + b[j];
                for (int k = j+1; k < n; ++k)
                    if ((a[i] + a[j] + a[k]) % 50 == 0)
                        if (b[i] + b[j] + b[k] > ans) ans = b[i] + b[j] + b[k];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
