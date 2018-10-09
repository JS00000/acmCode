// Farey sequence(法雷数列)
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

long double abs(long double x)
{
    return x < 0 ? -x : x;
}

unsigned long gcd(unsigned long a, unsigned long b)
{
    return b==0?a:gcd(b, a%b);
}

typedef struct _frac
{
    unsigned long numerator;
    unsigned long denominator;
    void div()
    {
        unsigned long d;
        d = gcd(numerator, denominator);
        if (d > 1) numerator /= d, denominator /= d;
    }
}FRAC;
 
long double getValue( FRAC f)
{
    long double t=(long double)f.numerator / (long double)f.denominator;
    return t;
}

//f必须为正数
void searchFrac( FRAC* pLow, FRAC* pHigh, int n, long double f)
{
    FRAC low;
    FRAC high;
    FRAC mid;
    int c;

    int k=(int)f;
    f -= (long double)k;
    
    low.numerator = 0;
    low.denominator = 1;
    high.numerator = 1;
    high.denominator = 1;

    mid.numerator = low.numerator + high.numerator;
    mid.denominator = low.denominator + high.denominator;

    while ( mid.denominator <= n )
    {
        if ( getValue(mid) > f)
            high=mid;
        else
            low=mid;
        mid.numerator = low.numerator + high.numerator;
        mid.denominator = low.denominator + high.denominator;
        mid.div();
    }
    
    if (k>0)
    {
        low.numerator += k * low.denominator;
        high.numerator += k * high.denominator;
    }
    
    low.div();
    high.div();

    *pHigh = high;
    *pLow = low;
}

int main(int argc, char* argv[])
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    FRAC low, high;
    int T, K;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &K);
        long double x;
        x = powl(K, (long double)2/3);
        searchFrac(&low,&high,100000,x);
        if (abs(x - getValue(low)) < abs(getValue(high) - x))
            printf("%lu/%lu\n", low.numerator,low.denominator);
        else
            printf("%lu/%lu\n", high.numerator,high.denominator);
    }
    return 0;
}
