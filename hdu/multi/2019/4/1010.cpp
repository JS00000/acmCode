#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn=10002; 
int prime[maxn+1];  
void getPrime( int n )
{
    memset(prime,0, sizeof(prime));
    for(int i=2;i<=n;i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1; j<=prime[0] && prime[j]<=n/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
long long n;

long long pp(long long x , int p)
{
    if ( p == 2 ) return x*x;
    else if (p==3) return x*x*x;
    return x*x*x*x;
}

bool check( long long x , int p )
{
    long long l = 1 , r,mid,tmp;
    if ( p == 2 ) r = 1e9;
    else if ( p == 3 ) r = 1e6;
    else r = 31623;
    while(l<r)
    {
        mid = (l+r)/2;
        tmp = pp(mid,p);
        if ( tmp==x ) return true;
        else if ( tmp < x ) l = mid + 1;
        else r = mid - 1;
    }
    if ( l == r && pp(l,p)==x ) return true;
    return false;
}

int solve()
{
    int mx = 100;
    
    scanf("%lld",&n);

    for( int k = 1; k <=prime[0] && prime[k] <= n; k++ )
    if(n % prime[k] == 0)
    {
        int cnt = 0;
        while( n % prime[k] == 0 ) n /= prime[k] , cnt++;
        if ( cnt == 1 ) return 1;
        mx = min(mx,cnt);
    }
    if(n>1)
    {
        if ( check(n,4) ) return min(4,mx);
        else if ( check(n,2) ) return min(2,mx);
        else if ( check(n,3) ) return min(3,mx);
        else mx = min(mx,1);    
    }

    return mx;
}

int main()
{
    //printf("%lld\n", (31623LL)*(31623LL)*(31623LL)*(31623LL) );
    int T;
    //printf("%0.6f\n",sqrt((double)1e9) );
    scanf("%d",&T);
    getPrime(10000);
    //printf("%d\n",prime[prime[0]-5] );
    while(T--)
    {
        printf("%d\n", solve());
    }
    return 0;
}
