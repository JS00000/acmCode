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
        double x;
        scanf("%lf", &x);
        printf("%s\n", x > 1 ? "No": "Yes");
    }
    return 0;
}
