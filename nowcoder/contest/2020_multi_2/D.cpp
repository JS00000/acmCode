#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int mini[51] = {0, 4, 6, 8, 8, 10, 10, 12, 12, 12, 14, 14, 14, 16, 16, 16, 16, 18, 18, 18, 18, 20, 20, 20, 20, 20, 22, 22, 22, 22, 22, 24, 24, 24, 24, 24, 24, 26, 26, 26, 26, 26, 26, 28, 28, 28, 28, 28, 28, 28, 30};

struct point
{
    int x,y;
    point(){}
    point(int a, int b) : x(a), y(b) {}
} p[50];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        if (m % 2 == 1 || m < mini[n] || m > n * 4) {
            printf("No\n");
        } else {
            printf("Yes\n");
            // int k = int(sqrt(n));
            int j = 0, x = 1, y = 1;
            while (j < n) {
                p[j].x = x;
                p[j].y = y;

                j++;
            }
        }
    }
    return 0;
}
