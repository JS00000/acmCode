#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;



int main()
{
    double sum1 = 0, sum2 = 1;
    double p = 0.7;
    for (int i = 1; i <= 100; i++) {
        sum1 += i*(1-p)*pow(p, i-1);
        sum2 += pow(p, i);
    }
    printf("%f %f\n", sum1, sum2);
    return 0;
}
