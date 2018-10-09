// 数学
#include "iostream"
#include "ctime"


using namespace std;


typedef long long LL;

const long long mod = 1000000007;
long long mul_mod(long long a, long long b)
{
    long long res = 0;
    int flag;
    if ( b < 0 ) {
        flag = 1;
        b = -b;
    } else flag = 0;
    while (b) {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
        a = (a << 1) % mod;
    }
    res %= mod;
    return (flag ? (~res + 1) : res);
}


long long pow(long long a, long long b, long long n)
{
    long long base = a;
    long long r = 1;
    while(b!=0)
    {
        printf("%lld     %lld  %lld        %lld\n", a, b, base, r);
        if (b&1) r=r*base%n;
        base=base*base%n;
        b>>=1;
    }
    return r;
}

LL exgcd(LL a,LL b,LL &x,LL &y)  //返回最大公约数，x，y存的是一组解
{
    if(b==0)
    {
        x=1 , y=0;
        return a;
    }
    LL r=exgcd( b , a % b , y , x );
    y -= x * (a/b);
    return r;
}

LL inv(LL a,LL m)
{
    LL d,x,y;
    d = exgcd( a , m , x , y );
    return d==1 ? (x%m+m)%m : -1;  //-1无解
}


long long qmul(long long a,long long b)
{
    long long ans=0;
    for(int i=b<0?-b:b;i;i>>=1,a=(a<<1)%mod)
        if(i&1)ans=(ans+a)%mod;
    return b<0?-ans:ans;
}

// b >= 0
long long qpow(long long a,long long b)
{
    unsigned long long ans=1;a%=mod;
    for(int i=b;i;i>>=1,a=a*a%mod)
        if(i&1)ans=ans*a%mod;
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    // clock_t start, finish;
    // start = clock();
    
    // cout << pow(3, 27, 1000000007);


    // finish = clock();
    // cout << "\nTime:" << double(finish - start) << endl;

    for (int i = 10; i > -10; i--)
        printf("%d\n", qmul(i, -102342348) == (long long)i * (-102342348) % mod);
    return 0;
}
