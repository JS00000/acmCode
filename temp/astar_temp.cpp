#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[2007], cnt[1007];

int main()
{
    for (int n = 1; n <= 6; n++) {
        for (int i = 0; i < n; i++)
            a[i*2] = i*2, a[i*2+1] = i*2+1;
        for (int i = 0; i <= n; i++)
            cnt[i] = 0;
        do {
            int t = 0;
            for (int i = 0; i < n*2-1; i++)
                if (a[i] == (a[i+1] ^ 1)) t++;
            cnt[t]++;
        } while (next_permutation(a,a+n*2));
        printf("n=%d\n", n);
        for (int i = 0; i <= n; i++)
            printf("%d %d\n", i, cnt[i]);
    }
    return 0;
}
