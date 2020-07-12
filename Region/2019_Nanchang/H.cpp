#include <cstdio>
#include <map>
#include <tr1/unordered_map>

using namespace std;
const int mod = 998244353;

tr1::unordered_map<long long,long long> val;

struct node
{
    long long a[2][2];
    void E()
    {
        a[0][0] = a[1][1] = 1;
        a[0][1] = a[1][0] = 0;
    }
    void init()
    {
        a[0][0] = 0 , a[0][1] = 2;
        a[1][0] = 1 , a[1][1] = 3;
    }
}p[70];

node multi( node &a , node &b )
{
    node c;
    for( int i = 0; i < 2; i++ )
        for( int j = 0; j < 2; j++ )
        {
            c.a[i][j] = 0;
            for( int k = 0; k < 2; k++ ) c.a[i][j] = ( c.a[i][j] + a.a[i][k] * b.a[k][j] % mod ) % mod;
        }
    return c;
}

long long calf( long long n )
{
    // if (val.find(n) != val.end()) return val[n];
    node ans;
    ans.E();
    int t = 1;
    while(n)
    {
        if ( n & 1 ) ans = multi( ans , p[t] );
        n>>=1;
        t++;
    }
    // val[n] = ans.a[1][0] % mod;
    return ans.a[1][0] % mod;
}

void init()
{
    //
    p[1].init();
    for( int i = 2; i < 70; i++ ) p[i] = multi( p[i-1] , p[i-1] );
}

int main()
{
    init();
    long long n,ans = 0,tmp;
    int Q;
    scanf("%d%lld",&Q,&n);
    tmp = calf(n);
    ans = calf(tmp^(2^q));
    printf("%lld\n",ans);
    return 0;
}
