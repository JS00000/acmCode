#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        double maxi = 0;
        for (int i = 0; i < n; i++) {
            int b;
            double c;
            scanf("%d%lf", &b, &c);
            maxi = max(maxi, (1 - c) / (b + 1 - c));
        }
        printf("%.5f\n", maxi);
    }
    return 0;
}
