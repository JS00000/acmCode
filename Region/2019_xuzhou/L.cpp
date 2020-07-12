#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define LL long long

int n;
long long dp[(1<<17)+10][20];
int f[2][7] = {0,3,4,5,4,7,8, 3,6,5,6,5,8,9};
struct point
{
    int x, y;
}p[20];

int dist(point p1, point p2) {
    int dx = abs(p1.x-p2.x);
    int dy = abs(p1.y-p2.y);
    int d1 = min(dx, dy);
    int d2 = max(dx, dy);
    if (d1 > 1) return d1 + d2;
    else {
        if (d2 < 7) return f[d1][d2];
        else return f[d1][3+(d2-3)%4] + (d2-3)/4*4;
    }
}



int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for( int i = 0; i < n; i++ ) scanf("%d%d",&p[i].x,&p[i].y);
        p[n].x = p[n].y = 0;
        memset(dp,0x3f,sizeof(dp));
        int uplime = 1<<n;

        for( int i = 0; i < n; i++ ) dp[1<<i][i] = dist( p[n] , p[i] );

        for( int i = 1; i < uplime; i++ )
            for( int j = 0; j < n; j++ )
            if ( i & (1<<j) ) //dp[i][j] -> dp[i|k][k]
            {
                for( int k = 0; k < n; k++ )
                    if ( !( i&(1<<k) ) && k!=j )
                    {
                        int nxt = i | (1<<k);
                        dp[nxt][k] = min( dp[nxt][k] , dp[i][j] + dist( p[j],p[k]) );
                    }
            }

        long long ans = 8e18;
        for( int i = 0; i < n; i++ ) ans = min( ans , dp[uplime-1][i] );
        printf("%lld\n",ans);
    }
    return 0;
}
