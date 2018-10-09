#include <stdio.h>
#include <algorithm>

using namespace std;

typedef unsigned long long LLU;
const LLU mod = 1000000007;

LLU n;

LLU multi(LLU a,LLU b,LLU p)   //大数 （a×b）%p
{
    int sign = 1;
    LLU ret=0;
    while(b)
    {
        if(b&1)
            ret=(ret+a)%p;
            a=(a+a)%p;  //a*2^0  a*2^1  a*2^2  a*2^4
            b>>=1;
    }
    return ret*sign;
}


LLU g( LLU n )
{
    LLU bit[100];
    LLU len = 0;
    LLU ans = 0;
    LLU temp = n;
    while(temp)
        bit[++len] = temp&1 , temp>>=1;

    LLU p = 2;

    for( LLU i = 1 ; i <= len; i++ , p<<=1 ){

        ans = (ans + (p/2)%mod * (  ((n+1)/p)%mod*((p/2)%mod )%mod ) %mod  ) % mod;
        if ( bit[i] == 1 ) {
            ans = (ans + (p/2)%mod * ( min( (n+1)%p , p/2 )%mod ) % mod ) % mod;
        }
        else {
            if ( (n+1) %p > ( p / 2 ) )
                ans = ( ans + (p/2) % mod * ( ( (n+1) %p - (p/2) )%mod )%mod ) % mod;

        }
    }
    return ans;
}

LLU f()
{
    LLU x = 1, sum = 0;
    while (x < n/2.) x *= 2;
    if (x > 1) sum = multi(x/2, x-1, mod);
    sum = ( g(n-x-1) + sum) % mod;
    sum = (( sum + n - 1) % mod+mod)%mod;
    return sum;
}

int main()
{
    while (~scanf("%llu", &n))
        if (n < 2) continue;
        else printf("%llu\n", f());
    return 0;
}
