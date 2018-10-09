#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn=2e3+10;
const int maxm=1e5+10;

struct coord{int x,y;}tmp,nxt;
queue<coord>q;

int T,m,res;
int x[maxm],y[maxm],ans[maxn];
int state[maxn][maxn];
int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};

void bfs(int x,int y)
{
    state[tmp.x=x][tmp.y=y]=2;
    res--,q.push(tmp);

    while(!q.empty())
    {
        tmp=q.front(),q.pop();
        for(int i=0;i<4;i++)
        {
            nxt.x=tmp.x+dir[i][0];
            nxt.y=tmp.y+dir[i][1];
            if(nxt.x<0||nxt.x>2000||nxt.y<0||nxt.y>2000)continue;
            if(state[nxt.x][nxt.y]!=0)continue;
            state[nxt.x][nxt.y]=2;
            res--,q.push(nxt);
        }
    }
}

bool check(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int xx=x+dir[i][0],yy=y+dir[i][1];
        if(xx<0||xx>2000||yy<0||yy>2000)continue;
        if(state[xx][yy]==2)return 1;
    }
    return 0;
}

int main()
{
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        x[i]+=1000,y[i]+=1000;
        state[x[i]][y[i]]=1;
    }

    res=2001*2001-m;
    bfs(0,0);

    for(int i=m;i;i--)
    {
        ans[i]=res++;
        state[x[i]][y[i]]=0;
        if(check(x[i],y[i]))bfs(x[i],y[i]);
    }

    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);

    return 0;
}
