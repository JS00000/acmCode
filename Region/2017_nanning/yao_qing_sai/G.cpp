#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000007
using namespace std;

int n, temp;
int a[maxn];


int main()
{
    while (~scanf("%d", &n)) {
        memset(a, 0, sizeof(int)*(n+1));
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            a[temp]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > 2) {
                ans  += (a[i] - 1) / 2;
                // printf("dui zi %d %d * %d\n", i, i, (a[i] - 1) / 2);
                a[i] -= (a[i] - 1) / 2 * 2;
            }
        }
        if (a[1] == 2) {
            a[1] = 0;
            ans++;
        }
        if (a[2] == 2) {
            a[2] = 0;
            ans++;
        }
        for (int i = 3; i <= n; i++) {
            // if (i == 3) 
                // printf("DE %d\n", a[i]);
            if (a[i] > 0 && a[i-1] == 1 && a[i-2] == 1) {
                ans++;
                a[i]--;
                a[i-1]--;
                a[i-2]--;
                // printf("shun zi %d %d %d\n", i-2, i - 1, i);
            } else if (a[i] == 2){
                a[i] = 0;
                ans++;
                // printf("dui zi %d %d \n", i, i);
            }
            // printf("--i = %d\n", i);
            // for (int j = 1; j <= n; j++) {
            //     printf("%d ", a[j]);
            // }
            // printf("\n");
        }
        printf("%d\n", ans);
    }
    return 0;
}
