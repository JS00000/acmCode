#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;
int num[30];
ULL f[30][30];

ULL sub(int l, int r)
{
    ULL ans = 0;
    for (int i = r; i >= l; i--)
    {
        ans = ans * 10ULL + num[i];
    }
    return ans;
}

int main()
{
    ULL n;
    int m;
    while (scanf("%llu%d", &n, &m) == 2)
    {
        int len = 0;
        while (n > 0)
        {
            num[len++] = n % 10;
            n /= 10;
        }
        for (int i = 0; i < len; i++)
        {
            f[i][1] = sub(0, i);
            for (int j = 2; j <= m; j++)
            {
                f[i][j] = 0;
                for (int k = 0; k < i; k++)
                {
                    f[i][j] = max(f[i][j], f[k][j - 1] * sub(k + 1, i));
                }
            }
        }
        printf("%llu\n", f[len - 1][m]);
    }
    return 0;
}
