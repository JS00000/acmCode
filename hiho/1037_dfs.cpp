#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int n;
int a[maxn][maxn], ma[maxn][maxn];

int dfs(int i, int j)
{
    if (i == n-1) return a[i][j];
    if (ma[i][j] > 0) return ma[i][j];
    ma[i][j] = a[i][j] + max(dfs(i+1, j), dfs(i+1, j+1));
    return ma[i][j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            scanf("%d", &a[i][j]), ma[i][j] = 0;
    printf("%d\n", dfs(0, 0));
    return 0;
}
