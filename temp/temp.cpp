#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

// const long long mod = 100000007;
// long long qpow(long long a,long long b)
// {
//     long long ans=1;a%=mod;
//     for(int i=b;i;i>>=1,a=a*a%mod)
//         if(i&1)ans=ans*a%mod;
//     return ans;
// }


// void show(long long x)
// {
// 	for (int i = 0; i < 64; ++i) printf("%lld", x&1), x >>= 1;
// 	printf("\n");
// }


void alt(double a[], int n)
{
    double b[n];
    for (int i = 0; i < (n+1)/2; i++) b[i] = a[i*2];
    for (int i = (n+1)/2; i < n; i++) b[i] = a[(i-(n+1)/2)*2+1];
    for (int i = 0; i < n; i++) a[i] = b[i];
    return;
}


int main()
{
	int n = 5;
    double x[12];
    for (int i = 0; i < 12; ++i)
        x[i] = i;
    alt(x, 12);
    for (int i = 0; i < 12; ++i)
        printf("%f ", x[i]);
    printf("\n");
    return 0;
}
