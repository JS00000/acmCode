// 组合异或求和
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=1e3+10;
const LL mod=1e6+3;
LL ans[maxn],c[maxn][maxn];
int n,a[maxn];
inline void Init()
{
    memset(c,0,sizeof(c));
    c[0][0]=1;
    for(int i=1;i<=maxn-2;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
}
int main()
{
    Init();
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),ans[i]=0;
        LL p=1;
        for(int i=0;i<=31;i++)
        {
            int x=0,y=0;
            for(int j=1;j<=n;j++)
            {
                if((a[j]>>i)&1)x++;
                else y++;
            }
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=j;k+=2)
                {
                    ans[j]=(ans[j]+c[x][k]*c[y][j-k]%mod*p)%mod;
                }
            }
            p=2*p%mod;
        }
        for(int i=1;i<n;i++)printf("%lld ",ans[i]);
        printf("%lld\n",ans[n]);
    }
    return 0;
}