#include <cmath>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <algorithm>
#define maxn 30007
using namespace std;

int n;
int a[5][maxn];
bitset<maxn> b[5][maxn];

struct node
{
    int rank, id;
    node(){};
    node(int r, int i):rank(r), id(i){};
}c[5][maxn];

bool cmp(node r, node t)
{
    return r.rank < t.rank;
}

int main()
{
    for (int k = 0; k < 5; ++k)
        for (int i = 0; i < maxn; ++i)
            b[k][i].reset();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d%d", &a[0][i], &a[1][i], &a[2][i], &a[3][i], &a[4][i]);
        c[0][i].rank = a[0][i];
        c[1][i].rank = a[1][i];
        c[2][i].rank = a[2][i];
        c[3][i].rank = a[3][i];
        c[4][i].rank = a[4][i];
        c[0][i].id = i;
        c[1][i].id = i;
        c[2][i].id = i;
        c[3][i].id = i;
        c[4][i].id = i;
    }
    sort(c[0]+1, c[0]+n+1, cmp);
    sort(c[1]+1, c[1]+n+1, cmp);
    sort(c[2]+1, c[2]+n+1, cmp);
    sort(c[3]+1, c[3]+n+1, cmp);
    sort(c[4]+1, c[4]+n+1, cmp);
    for (int i = 2; i <= n; ++i)
    {
        b[0][i] = b[0][i-1];
        b[0][i][c[0][i-1].id] = 1;
        b[1][i] = b[1][i-1];
        b[1][i][c[1][i-1].id] = 1;
        b[2][i] = b[2][i-1];
        b[2][i][c[2][i-1].id] = 1;
        b[3][i] = b[3][i-1];
        b[3][i][c[3][i-1].id] = 1;
        b[4][i] = b[4][i-1];
        b[4][i][c[4][i-1].id] = 1;
    }
    for (int i = 1; i <= n; ++i)
        printf("%lu\n", (b[0][a[0][i]] & b[1][a[1][i]] & b[2][a[2][i]] & b[3][a[3][i]] & b[4][a[4][i]]).count());
    return 0;
}
