#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 300007
using namespace std;

int n, f[maxn];

int main()
{
    scanf("%d", &n);
    memset(f, 0, sizeof(int) * (n+1));
    f[n] = 2;
    printf("1");
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        temp--;
        f[temp] = 1;
        ans++;
        if(f[temp + 1] == 2) 
            while (temp >= 0 && f[temp] == 1) {
                f[temp--] = 2;
                ans--;
            }
        printf(" %d", ans);
    }
    printf("\n");
    return 0;
}
