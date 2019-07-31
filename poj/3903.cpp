#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 100007
using namespace std;

int a[maxn];
int b[maxn];

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
            b[i] = 0x7fffffff;
        }
        int tail = 0;
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(b, b + tail + 1, a[i]) - b;
            b[pos] = a[i];
            if (pos == tail) tail++;
        }
        printf("%d\n", tail);
    }
    return 0;
}
