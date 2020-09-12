#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

double x[101];
double x2[201];
double x4[401];
int dp[400];

int main()
{
    for (int i = 0; i <= 100; i++) {
        if (i >= 95) {
            x[i] = 4.3;
        } else if (i >= 90) {
            x[i] = 4.0;
        } else if (i >= 85) {
            x[i] = 3.7;
        } else if (i >= 80) {
            x[i] = 3.3;
        } else if (i >= 75) {
            x[i] = 3.0;
        } else if (i >= 70) {
            x[i] = 2.7;
        } else if (i >= 67) {
            x[i] = 2.3;
        } else if (i >= 65) {
            x[i] = 2.0;
        } else if (i >= 62) {
            x[i] = 1.7;
        } else if (i >= 60) {
            x[i] = 1.0;
        } else {
            x[i] = 0.0;
        }
        // printf("x[%d] = %.1f\n", i, x[i]);
    }
    for (int i = 0; i <= 200; i++) {
        x2[i] = 0;
        for (int j = max(0, i-100); j <= min(i, 100); j++) {
            x2[i] = max(x2[i], x[j] + x[i-j]);
        }
        // printf("x2[%d] = %.1f\n", i, x2[i]);
    }
    for (int i = 0; i <= 400; i++) {
        x4[i] = 0;
        for (int j = max(0, i-200); j <= min(i, 200); j++) {
            x4[i] = max(x4[i], x2[j] + x2[i-j]);
        }
        // printf("x4[%d] = %.1f\n", i, x4[i]);
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int s;
        scanf("%d", &s);
        printf("%.1f\n", x4[s]);
    }
    return 0;
}
