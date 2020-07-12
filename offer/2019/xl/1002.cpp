#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200007
using namespace std;

int a[maxn];
int f[maxn];

int main()
{
    int j = 0;
    while (~scanf("%d", a+j)) j++;
    int n = j / 2;
    int v = a[j-1];
    for (int i = 0; i < n; i++) {
        for (int k = v; k >= a[i]; k--) {
            f[k] = max(f[k], f[k-a[i]] + a[i+n]);
        }
    }
    int ma = 0;
    for (int i = 0; i <= v; i++) 
        ma = max(ma, f[i]);
    printf("%d\n", ma);
    return 0;
}
