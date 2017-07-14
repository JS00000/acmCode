#include <cstdio>
#include <cstdlib>
#include <cmath>

int main(void){
    double n, m;
    long long left, right, mid;

    while(scanf("%lf%lf",&n,&m)!=EOF){
        left = 0;
        right = 1000000002;
        while (right - 0.00000001 > left){
            mid = (left + right) / 2;
            if (pow(mid, n) - m > 0){
                right = mid;
            }
            else if (pow(mid, n) - m < 0){
                left = mid;
            }
            else{
                printf("%.0lld\n", mid);
                break;
            }
        }
    }
    return 0;
}