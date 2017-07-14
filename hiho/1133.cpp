#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000007
using namespace std;

int n, k;
int a[maxn];

int find_k(int a[], int l, int r, int k)
{
    int mid = (l+r)/2;
    return 0;
}


int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);
    printf("%d\n", find_k(a, 0, n, k));
    return 0;
}
