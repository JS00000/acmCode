#include <cstdio>
 
using namespace std;
const int mod = 998244353;
const int maxn = 1e6+9;
long long fac[maxn*2];
 
long long pow_mod(long long a,int b,int m)
{
    long long ans = 1;
    while(b){
        if ( b & 1 ) ans = ans * a % m;
        a = a * a % m;
        b>>=1;
    }
    return ans;
}
 
int main()
{
    fac[0] = 1;
    for( int i = 1; i <= 2000002; i++ ) fac[i] = fac[i-1] * i % mod;
 
    int n;
    while(scanf("%d",&n)==1){
        //(2n+1)!/n!^2
        long long x = pow_mod(fac[n],mod-2,mod);
        long long q = fac[2*n+1] * x % mod * x % mod;
        printf("%lld\n",pow_mod(q,mod-2,mod) );
    }
    return 0;
}