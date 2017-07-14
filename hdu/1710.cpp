// 二叉树前序中序求后序 hdu1710
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int n, pind;
int PreO[maxn], InO[maxn], PostO[maxn];

void solve(int Pl, int Pr, int Il, int Ir)
{
    if (Pl > Pr || Il > Ir) return;
    int i;
    for (i = Il; InO[i] != PreO[Pl] && i < Ir; i++);
    solve(Pl+1, Pl+i-Il, Il, i-1);
    solve(Pl+i-Il+1, Pr, i+1, Ir);
    PostO[pind++] = PreO[Pl];
}

int main()
{
    while(~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i) scanf("%d", &PreO[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &InO[i]);
        pind = 0;
        solve(0, n-1, 0, n-1);
        for (int i = 0; i < n-1; ++i)
            printf("%d ", PostO[i]);
        printf("%d\n", PostO[n-1]);
    }
    return 0;
}
