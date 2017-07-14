#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;



int main()
{
    int n;
    char c[10];
    scanf("%d%s", &n, c);
    int m = 1, tot = 1;
    while (tot + (m+2)*2 <= n) m += 2, tot += m*2;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
            if (!(i+j>=m && j>i))
                printf("%c", ((j>=i&&i+j<m) || (j<=i&&i+j>=m-1)) ? c[0] : ' ' );
        printf("\n");
    }
    printf("%d\n", n - tot);
    return 0;
}
