#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;



int main()
{
    int l, k;
    double r;
    scanf("%d%lf", &l, &r);
    while (l--) {
        scanf("%d", &k);
        printf("%d %d\n", k, int(r * ( 2 / sqrt(3) - 1) * pow( sqrt(3) / 3, k - 1)) );
    }
    scanf("%d", &k);
    return 0;
}
