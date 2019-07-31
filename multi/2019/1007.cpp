#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int a[16];
bool f[16];

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int i0, j0;
        for (int i = 0; i < 16; i++) {
            scanf("%d", a+i);
            f[i] = 0;
            if (a[i] == 0) {
                i0 = i / 4;
                j0 = i % 4;
            }
        }
        while (i0 < 4) {
            swap(a+i0*4+j0, a+(i0+1)*4+j0);
            i0++;
        }
        while (j0 < 4) {
            swap(a+12+j0, a+13+j0);
            j0++;
        }
        // for (int i = 0; i < 4; i++) {
        //     for (int j = 0; j < 4; j++) {
        //         printf("%d ", a[i*4+j]);
        //     }
        //     printf("\n");
        // }
        int cnt = 0;
        for (int i = 0; i < 15; i++) {
            if (!f[i]) {
                int j = i;
                int nn = 0;
                while (!f[j]) {
                    f[j] = 1;
                    j = a[j] - 1;
                    nn++;
                }
                cnt += nn - 1;
            }
        }
        // printf("%d\n", cnt);
        if (cnt % 2 == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
