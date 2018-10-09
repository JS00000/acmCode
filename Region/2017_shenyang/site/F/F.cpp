#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

const double eps = 1e-12;

double area(double t) 
{
    return t / 4 * sqrt( 3 * ( t * t - 4 ) );
}

int f(int x)
{
    if (x == 0) return 2;
    if (x == 1) return 4;
    return f(x - 1) * 4 - f(x - 2);
}

int main()
{
    int t, k = 0;
    double A;
    for (int i = 2; i < 100000; i++) {
        t = i;
        A = area(t);
        if (fabs(A - int(A + 0.5)) < eps) {
            printf("%6d %6d %f\n", t, f(k++), A);
        }
    }
    return 0;
}
