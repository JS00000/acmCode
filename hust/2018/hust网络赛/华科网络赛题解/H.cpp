#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500000;
const int maxm=100000;
struct node{
    int op,x,y,z,t,id;
}p[maxn],s[maxn];
int num,w,tot;
int h[maxm],ans[maxn];
bool cmp(const node &a,const node &b){
    return a.x<b.x;
}
void query(int i,int op,int x,int y,int z,int id) {
    p[i].id=i;p[i].op=op;p[i].x=x;p[i].y=y;p[i].z=z;p[i].t=id;
}
void add(int pos,int x){
    while(pos<=w)
        h[pos]+=x,pos+=(pos&(-pos));
}
ll sum(int pos){
    ll t=0;
    while(pos>0)
        t+=h[pos],pos-=(pos&(-pos));
    return t;
}
void solve(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1,t1=l-1,t2=mid,t=l;
    for(int i=l;i<=r;i++)
        if(p[i].id<=mid) s[++t1]=p[i];
        else s[++t2]=p[i];
    memcpy(p+l,s+l,sizeof(node)*(r-l+1));
    for(int i=mid+1;i<=r;i++)
        if(p[i].op==2){
        for(;t<=mid&&p[t].x<=p[i].x;t++)
            if(p[t].op==1) add(p[t].y,p[t].z);
        ans[p[i].t]+=sum(p[i].y)*p[i].z;
    }
    for(int i=l;i<t;i++)
        if(p[i].op==1) add(p[i].y,-p[i].z);
    solve(l,mid);solve(mid+1,r);
}
int main(){
    int k,x,y,x1,y1,x2,y2,hh,n;
    scanf("%d%d",&n,&w);
    while(n--){
        scanf("%d",&k);
        if(k==1){
            scanf("%d%d%d",&x,&y,&hh);
            query(++tot,1,x,y,hh,0);
        }else{
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2); num++;
            query(++tot,2,x2,y2,1,num);
            query(++tot,2,x1-1,y1-1,1,num);
            query(++tot,2,x1-1,y2,-1,num);
            query(++tot,2,x2,y1-1,-1,num);
        }
    }
    sort(p+1,p+1+tot,cmp);
    solve(1,tot);
    for(int i=1;i<=num;i++)
        printf("%d\n",ans[i]);
    return 0;
}
