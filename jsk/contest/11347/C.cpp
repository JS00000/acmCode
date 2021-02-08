#include<bits/stdc++.h>
using namespace std;
const int maxn=300010;
struct node{ 
    int val,l,r; 
    node() {} 
    node(int L,int R,int V):l(L),r(R),val(V){}
}s[maxn*20];
int rt[maxn],cnt,ans;
void insert(int &now,int pre,int L,int R,int pos,int val)
{
    s[now=++cnt]=node(s[pre].l,s[pre].r,s[pre].val+val);
    if(L==R) return ;
    int Mid=(L+R)>>1;
    if(pos<=Mid) insert(s[now].l,s[pre].l,L,Mid,pos,val);
    else insert(s[now].r,s[pre].r,Mid+1,R,pos,val);
}
int query(int now,int pre,int L,int R,int times)
{
    if(L==R) return L;
    int Mid=(L+R)>>1;
    int res=maxn,tmp;
    if(s[s[now].l].val-s[s[pre].l].val>times){
         tmp=query(s[now].l,s[pre].l,L,Mid,times);
         if(tmp!=-1) res=min(res,tmp);
    }
    if(s[s[now].r].val-s[s[pre].r].val>times){
         tmp=query(s[now].r,s[pre].r,Mid+1,R,times);
         if(tmp!=-1) res=min(res,tmp);
    }
    if(res==maxn) res=-1;
    return res;
}
int main()
{
    int N,K,Q,x,y,i,j;
    scanf("%d%d",&N,&Q);
    for(i=1;i<=N;i++){
        scanf("%d",&x);
        insert(rt[i],rt[i-1],1,N,x,1);
    }
    for(i=1;i<=Q;i++){
        scanf("%d%d%d",&x,&y,&K);
        printf("%d\n",query(rt[y],rt[x-1],1,N,(y-x+1)/K));
    }
    return 0;
}
