#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+500;
const int INF = 0x3f3f3f3f;
bool vis[maxn];
int ans[maxn];
queue<int> q;
int a,b;
int f(int x){
    int n;
    for(n=0; x; n++) x &= x-1;
    return n;
}
void bfs(){
    for(int i=0;i<maxn;i++) ans[i]=INF;
    ans[a]=0;
    memset(vis,0,sizeof(vis));
    int cur=a;
    vis[a]=1;
    q.push(cur);
    while(!q.empty()){
        cur=q.front();
        q.pop();
        int tmp[4]={cur+1,cur-1,cur+f(cur),cur-f(cur)};
        for(int i=0;i<4;i++){
            if(tmp[i]<0) continue;
            if(!vis[tmp[i]]){
                vis[tmp[i]]=1;
                q.push(tmp[i]);
                ans[tmp[i]]=ans[cur]+1;
            }
            if(tmp[i]==b) return;
        }
    }
    return;
}
int main(){
    cin>>a>>b;
    bfs();
    cout<<ans[b]<<endl;
}
