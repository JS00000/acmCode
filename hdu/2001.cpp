#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    double x1, x2, y1, y2;
    while(~scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2))
        printf("%.2f\n", sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)));
    return 0;
}
