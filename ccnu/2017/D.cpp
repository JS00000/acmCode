#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<iostream>
#include<cassert>
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int n,m,K,stx,sty;
char a[1010][1010];
int be[1010][1010];
bool v[1010][1010];
vector<int> own[1010][1010];
pair<int,int> aa[20000];
int b[20000];
int de[20000];
const char d[4]={'w','e','n','s'};
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};
int c[1010][1010];

bool flag;

queue<pair<int ,int > > q;

inline bool judge(int x,int y){

    for (int tt=0;tt<4;tt++) 
    {
        if (x+dx[tt]<=0 || x+dx[tt]>n || y+dy[tt]<=0 || y+dy[tt]>m) continue;
        if(v[x+dx[tt]][y+dy[tt]]) return true;
    }
    return false;
}

inline void clear_master(int t){
            int x=aa[t].first;
            int y=aa[t].second;
            int tt;
            for (tt=0;tt<4;tt++) if (d[tt]==a[x][y]) break;
            for (int i=0;i<=b[t];i++){
                if (x+dx[tt]*i<=0 || x+dx[tt]*i>n || y+dy[tt]*i<=0 || y+dy[tt]*i>m) break;
                c[x+dx[tt]*i][y+dy[tt]*i]--;
                if(c[x+dx[tt]*i][y+dy[tt]*i] == 0 && judge(x+dx[tt]*i,y+dy[tt]*i))
                    q.push(make_pair(x+dx[tt]*i,y+dy[tt]*i)),v[x+dx[tt]*i][y+dy[tt]*i] = 1;
            }
}
int bfs(){
    rep(i,1,n)
     rep(j,1,m)
      v[i][j]=0;
    while (!q.empty()) q.pop();
    q.push(make_pair(stx,sty));
    if (c[stx][sty]!=0) return 0;
    v[stx][sty]=1;
    int ans=0;
    while (!q.empty()){
        pair<int ,int > now = q.front();
        q.pop();
        for (int i=0;i<own[now.first][now.second].size();i++){
            ans++;
            //printf("%d %d %d\n",now.first,now.second,own[now.first][now.second][i]);
            clear_master(own[now.first][now.second][i]);
            //rep(a,1,n)
            //{
            //  rep(b,1,m)
            //  printf("%d",c[a][b]);
            //  puts("");
            //}
        }
        for (int i=0;i<4;i++){
            int x=now.first+dx[i];
            int y=now.second+dy[i];
            if (x>0 && x<=n && y>0 && y<=m && c[x][y]==0 && !v[x][y]){
                v[x][y]=1;
                q.push(make_pair(x,y));
            }
        }
    }
    return ans;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("D.in","r",stdin);
    //freopen("D.ans","w",stdout);
    int T;
    scanf("%d",&T);
    for (int test=1;test<=T;test++){
        flag=true;
        scanf("%d%d%d",&n,&m,&K);
        rep(i,1,K) scanf("%d",&b[i]);
        rep(i,1,n)
            scanf("%s",a[i]+1);
        rep(i,1,n)
         rep(j,1,m)
          c[i][j]=0;
        rep(i,1,n)
         rep(j,1,m)
          if (a[i][j]=='1'){
                stx=i;
                sty=j;
                break;
          }
        rep(i,1,n)
         rep(j,1,m){
             c[i][j]=0;
             own[i][j].clear();
         }
          {
            int kk=1;
            rep(i,1,n)
             rep(j,1,m)
              if (a[i][j]>='a' && a[i][j]<='z'){
                 aa[kk]=make_pair(i,j);
                 int t;
                 for (t=0;t<4;t++) if (d[t]==a[i][j]) break;
                 int x=i,y=j;
                 if (x-dx[t]<=0 || y-dy[t]<=0 || x-dx[t]>n || y-dy[t]>m){
                    flag=false;
                 } else {
                     own[x-dx[t]][y-dy[t]].push_back(kk);
                 }
                 rep(k,0,b[kk]){
                    c[x][y]++;
                    x=x+dx[t];
                    y=y+dy[t];
                    if (x<=0 || y<=0 || x>n || y>m) break;
                 }
                 kk++;
              }
          }
          printf("CASE #%d: %d\n",test,bfs());
    }
    return 0;
}
