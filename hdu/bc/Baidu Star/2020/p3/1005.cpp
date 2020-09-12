#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
const int mod = 1e9+7;

int n,m;
long long f[1002][1002];
long long fact[20];

long long dfs( int n , int m )
{
    if ( f[n][m] != -1 ) return f[n][m];
    if ( n < m ) return 0;
    if ( m == 0 ) return 1;
    if ( n == 0 ) return 0;
    if ( n == m && m <= 10 ) return fact[m];
    long long ans = 0;
    long long tmp = n,s = 1;
    int cnt = 10;
    for( int nn = n-2 , mm = m-1; cnt && nn >= 0 && mm >= 0; nn-- , mm-- , cnt-- )
    {
        s = (s*tmp)%mod;
        tmp--;
        ans = ans + s * dfs(nn,mm)%mod;
        if ( ans >= mod ) ans -= mod;
    }
    ans = ans + dfs(n-1,m);
    if ( ans >= mod ) ans -= mod;
    return f[n][m] = ans;
}
long long solve()
{
    if ( n == 1 ){
        if ( m == 0 ) return 1;
        return -1;
    }
    int mx = (n-2)/11*10 + (n-2)%11;
    if ( m > mx ) return -1;
    return dfs(n-2,m);
}


int main()
{
    memset(f,-1,sizeof(f));
    fact[1] = 1;
    for( int i = 2; i <= 10; i++ ) fact[i] = fact[i-1] * i;
    
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        printf("%lld\n",solve());
    }
    return 0;
}