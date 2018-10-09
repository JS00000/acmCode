// AC
#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<cstdlib>  
#include<cmath>  
#include<cstring>  
#include<string>  
#include<climits>  
#include<queue>  
#include<stack>  
#include<map>  
#include<set>  
#define N 2000001  
#define M 8000010  
#define inf 1<<26  
#define p(a,b) m*(a-1)+b  
using namespace std;  
inline int read()  
{  
    int x=0,f=1;char ch;  
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  
    return x*f;  
}  
int n,m,s,t;  
int head[N],pos=-1,cur[N];  
struct edge{int to,next,c;}e[M];  
void add(int a,int b,int c)  
{pos++;e[pos].to=b,e[pos].next=head[a],e[pos].c=c,head[a]=pos;}  
void insert(int a,int b,int c){add(a,b,c);add(b,a,c);}  
  
queue<int>Q;bool vis[N];int d[N];  
bool bfs()  
{  
    for(int i=s;i<=t;i++)vis[i]=0,d[i]=-1;  
    while(!Q.empty())Q.pop();  
    d[s]=0,vis[s]=1;Q.push(s);  
    while(!Q.empty())  
    {  
        int u=Q.front();Q.pop();  
        for(int i=head[u];i!=-1;i=e[i].next)  
        {  
            int v=e[i].to;  
            if(e[i].c<=0||vis[v])  
                continue;  
            d[v]=d[u]+1;  
            vis[v]=1;Q.push(v);  
            //if(v==t)return true;  
        }  
    }return vis[t];  
}  
int dfs(int u,int a)  
{  
    if(u==t||!a)return a;  
    int flow=0,f;  
    for(int &i=cur[u];i!=-1;i=e[i].next)  
    {  
        int v=e[i].to;  
        if(d[v]==d[u]+1&&(f=dfs(v,min(a,e[i].c)))>0)  
        {  
            flow+=f,a-=f;  
            e[i].c-=f,e[i^1].c+=f;  
            if(!a)break;  
        }  
    }return flow;  
}  
int dinic()  
{  
    int ret=0;  
    while(bfs())  
    {  
        for(int i=s;i<=t;i++)cur[i]=head[i];  
        ret+=dfs(s,inf);   
    }return ret;  
}  
  
void init(){memset(head,-1,sizeof(head));}  
  
int main()  
{  
    n=read(),m=read();  
    s=1,t=n*m;init();  
    for(int i=1;i<=n;i++)  
        for(int j=1;j<m;j++)  
        {  
            int x=read();  
            insert(p(i,j),p(i,j+1),x);  
        }  
    for(int i=1;i<n;i++)  
        for(int j=1;j<=m;j++)  
        {  
            int x=read();  
            insert(p(i,j),p(i+1,j),x);  
        }  
    for(int i=1;i<n;i++)  
        for(int j=1;j<m;j++)  
        {  
            int x=read();  
            insert(p(i,j),p(i+1,j+1),x);   
        }  
    printf("%d\n",dinic());  
}  