#include <cstdio>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
#define rep(i,j,k) for (int i=j;i<=k;i++)
#define Rrep(i,j,k) for (int i=j;i>=k;i--)
#define LL long long

const int mod = 1000000009;

map< pair<long long,long long> , int > f;

struct node
{
    LL p[2][2];
};
 
node multi( node &x , node &y )
{
    node ans;
    rep(i,0,1)
        rep(j,0,1)
        {
            ans.p[i][j] = 0;
            rep(k,0,1)
                ans.p[i][j] = ( ans.p[i][j] + x.p[i][k] * y.p[k][j] ) % ( mod - 1 );
        }
    return ans;
}
 
LL fib( long long t )
{
    if ( t < 3 ) return 1;
    t -= 2;
    node ans,temp;
    temp.p[0][0] = 0;
    temp.p[0][1] = temp.p[1][0] = temp.p[1][1] = 1;

    ans.p[0][0] = ans.p[1][1] = 1;
    ans.p[0][1] = ans.p[1][0] = 0;
    while( t )
    {
        if ( t & 1 ) ans = multi( ans , temp );
        temp = multi( temp , temp );
        t >>= 1;
    }
    return ( ans.p[1][0] + ans.p[1][1] ) % mod;
}
 
LL pow_mod( LL a , LL b )
{
    a %= mod;
    LL ans = 1;
    while( b )
    {
        if ( b & 1 ) ans = ( ans * a ) % mod;
        a = ( a * a ) % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    long long n,c,k;
    long long tmp,last = 0;
    pair<long long,long long> x;

    while(scanf("%lld",&c)==1){
        f.clear();
        for( long long i = 1; ; i++ ){
            tmp = fib(c*i);
            x = make_pair(last,tmp);
            if ( f[ x ] != 0 )
                {
                    printf("period : %d\n",(i*c - f[x])/c );
                    break;
                }
            f[x] = i*c;
            last = tmp;
            //f[tmp] = 1;
        }
    }
    
    return 0;
}