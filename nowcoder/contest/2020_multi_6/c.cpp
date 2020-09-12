#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 207
using namespace std;

int a[maxn][maxn];
int b[maxn][maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        double maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                if (i == 0) b[i][j] = a[i][j];
                else b[i][j] = b[i-1][j] + a[i][j];
                maxi = max(maxi, double(b[i][j]) / a[i][j]);
            }
        }
        printf("%.8f\n", maxi);
    }
    return 0;
}
