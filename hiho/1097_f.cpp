#include <cstdio>
inline int getc(){
    static char buf[1<<15],*S=buf,*T=buf;
    if(S==T)if(T=(S=buf)+fread(buf,1,1<<15,stdin),S==T)return 0;
    return*S++;
}
int aa,ch;inline int F(){
    while(ch=getc(),ch<48||ch>57){};aa=ch-48;
    while(ch=getc(),ch>47&&ch<58)aa=aa*10+ch-48;return aa;
}
int n,r,i,j,d[1010],map[1010][1010],k,l,vis[1010],ans;
int main(){
    for(n=F(),i=1;i<=n;i++)
    for(j=1;j<=n;j++)map[i][j]=F();
    for(i=1;i<=n;i++)d[i]=map[1][i];
    for(vis[1]=1,d[0]=1<<30,i=2;i<=n;i++){
        for(k=0,j=2;j<=n;j++)
        if(!vis[j]&&d[j]<d[k])k=j;
        vis[k]=1;ans+=d[k];
        for(j=2;j<=n;j++)l=map[k][j],d[j]>l?d[j]=l:1;
    }
    printf("%d\n",ans);
}
