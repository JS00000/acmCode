#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int tot = 240 - k, i = 0;
    while(tot - i*5 >= 0) tot -= i*5, i++;
    printf("%d\n", min(--i, n));
    return 0;
}
