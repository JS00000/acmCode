#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

int n, m, k;
int mat[maxn][maxn];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int ans = 0, cut = 0;
    for (int j = 0; j < m; j++) {
        int score = 0;
        for (int i = 0; i < k; i++) {
            score += mat[i][j] == 1;
        }
        int ma = score;
        int flag = 0;
        for (int i = k; i < n; i++) {
            if (mat[i-k][j] == 0 && mat[i][j] == 1) {
                score++;
                if (score > ma) {
                    ma = score;
                    if (flag) {
                        cut+=flag;
                        flag = 0;
                    }
                }
            } else if (mat[i-k][j] == 1) {
                flag++;
                if (mat[i][j] == 0) score--;
            }
        }
        ans += ma;
    }
    printf("%d %d\n", ans, cut);
    return 0;
}
