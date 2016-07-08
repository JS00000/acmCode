#include<cstdio>
#include<cstring>
const int maxn=2005,maxm=20005;
int m,n;
int map[maxm][3]={},cost[maxn]={};
bool updated=true;
int times=0;
int main(){
    while (scanf("%d%d\n",&n,&m) == 2)
    {
        memset(map, 0, sizeof(map));
        memset(cost, 0, sizeof(cost));
        updated = true;
        times = 0;
        for(int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(z==1){
                map[i][0]=x;
                map[i][1]=y;
                map[i][2]=z;
            }else if(z==0){
                map[i][0]=x;
                map[i][1]=y;
                map[i][2]=z;
                i++;m++;
                map[i][1]=x;
                map[i][0]=y;
                map[i][2]=z;
            }else{
                map[i][0]=y;
                map[i][1]=x;
                map[i][2]=1;
            }
        }
        while(updated&times<=n){
            updated=false;
            times++;
            for(int i=0;i<m;i++){
                int preput=cost[map[i][0]]+map[i][2];
                if(cost[map[i][1]]<preput){
                    cost[map[i][1]]=preput;
                    updated=true;
                }else;
            }
        }
        if(times<=n){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(ans<cost[i])ans=cost[i];
                else;
            }
            printf("%d\n",ans);
        }else printf("Someone is lying!\n");
    }
}
