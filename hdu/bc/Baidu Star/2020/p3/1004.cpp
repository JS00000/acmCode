#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int x1max = 0;
        int x2max = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == 1) x1max = max(x1max, y);
            if (x == 2) x2max = max(x2max, y);
            if (x2max > 0 && x1max > 0 && x2max + 1 == x1max) maxi = max(maxi, x+y+1);
            else maxi = max(maxi, x+y);
        }
        printf("%d\n", maxi);
    }
    return 0;
}
