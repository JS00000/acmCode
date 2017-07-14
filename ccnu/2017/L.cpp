#include <stdio.h>
#include <string.h>

int vis[1005];

int main()
{
    //freopen("L.in","r",stdin);
    //freopen("L.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            vis[x]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0) ans++;
        }
        if(ans==0) printf("CASE #%d: Congratulations!\n",cas);
        else printf("CASE #%d: %d\n",cas,ans);
    }
    return 0;
}
