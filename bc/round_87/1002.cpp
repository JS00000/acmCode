#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

const int maxn = 1005;

bitset<maxn> f[maxn];
char s[maxn],t[maxn];
int n,m;

void work()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for(int i = 1;i <= n;i ++) f[i].reset();
    f[n / 2 + 1][0] = 1;
    for(int i = n / 2;i;i --)
    {
        char c = s[i],c1 = s[i + n / 2];
        f[i] |= (f[i + 1] << 2);
        if (c == c1) f[i] |= f[i + 1];
        if (c != c1) f[i] |= (f[i + 1] << 1);
    }
    if (!f[1][m]) printf("Impossible\n"); else
    {
        for(int i = 1;i <= n / 2;i ++)
            for(int j = 'a';j <= 'z';j ++)
            {
                int x = 0;
                if (j != s[i]) ++ x;
                if (j != s[i + n / 2]) ++ x;
                if (m < x) continue;
                if (f[i + 1][m - x]) {t[i] = j;m -= x;break;}
            }
        for(int i = 1;i <= n / 2;i ++)
            printf("%c", t[i]);
        for(int i = n / 2 + 1;i <= n;i ++)
            printf("%c", t[i - n / 2]);
        printf("\n");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for(;t;t --) work();
    return 0;
}