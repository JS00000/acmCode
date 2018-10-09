// 二维树状数组 Fenwick_tree
#include <stdio.h>

#define maxn 1007
const int mod = 1000000007;

inline int lowbit(int x)
{
    return x&(-x);
}

int N, M;
int BIT2[maxn][maxn];

void add(int x, int y, int val) {
    for(int i = x; i <= N; i += lowbit(i)) {
        for(int j = y; j <= N; j += lowbit(j)) {
            BIT2[i][j] = ((BIT2[i][j] + val) % mod + mod) % mod;
        }
    }
}

int sum(int x, int y) {
    int ret = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        for(int j = y; j > 0; j -= lowbit(j)) {
            ret = ((ret + BIT2[i][j]) % mod + mod) % mod;
        }
    }
    return ret;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            BIT2[i][j] = 0;
    char command[10];
    int a, b, x, y;
    int v;
    for (int i = 0; i < M; i++) {
        scanf("%s", command);
        if (command[0] == 'A') {
            scanf("%d%d%d", &x, &y, &v);
            add(x+1, y+1, v);
        } else if (command[0] == 'S') {
            scanf("%d%d%d%d", &a, &b, &x, &y);
            printf("%d\n", ((sum(x+1, y+1) - sum(x+1, b) - sum(a, y+1) + sum(a, b)) % mod + mod) % mod);
        }
    }
    return 0;
}
