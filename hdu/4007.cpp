#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int x,y;
}p[1001];
int n,ans,r,xx[1001],yy[1001];
int main()
{
    while(scanf("%d %d",&n,&r)==2)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&p[i].x,&p[i].y);
            yy[i]=p[i].y;
        }
        sort(yy+1,yy+1+n);
        ans=0;
        for(int j=1;j<=n;j++)//枚举下边界
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
                if(p[i].y>=yy[j]&&p[i].y<=yy[j]+r)
                    xx[cnt++]=p[i].x;//找出所有满足当前下边界的点
            sort(xx,xx+cnt);
            xx[cnt]=INT_MAX;//用来退出while循环
            int e=0;
            for(int i=0;i<cnt;i++)//求出以当前点位左边界的，边长为r的边，最多可覆盖的点
            {
                while(xx[e]<=xx[i]+r) e++;
                ans=max(ans,e-i);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
