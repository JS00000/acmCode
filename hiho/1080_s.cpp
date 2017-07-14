#include <cstdio>
int aa,bb;char ch;int F(){
    while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-'){};ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
    while(ch=getchar(),ch>='0'&&ch<='9')aa=aa*10+ch-'0';return bb?aa:-aa;
}
#define N 800010
int n,m,set[N],add[N],sum[N],op,x,y,v;
void bt(int o,int l,int r){
    if(l==r){
        sum[o]=F();
        return;
    }
    int mid=(l+r)>>1;
    bt(o<<1,l,mid),bt(o<<1|1,mid+1,r);
    sum[o]=sum[o<<1]+sum[o<<1|1];
}
void update(int o,int l,int r){
    if(x<=l&&r<=y){
        if(op==0){
            add[o]+=v;
            sum[o]+=v*(r-l+1);
        }
        else{
            set[o]=v;add[o]=0;
            sum[o]=v*(r-l+1);
        }
        return;
    }
    int mid=(l+r)>>1;
    if(set[o]){
        set[o<<1]=set[o<<1|1]=set[o];
        add[o<<1]=add[o<<1|1]=0;
        sum[o<<1]=set[o]*(mid-l+1);
        sum[o<<1|1]=set[o]*(r-mid);
        set[o]=0;
    }
    if(add[o]){
        add[o<<1]+=add[o];
        add[o<<1|1]+=add[o];
        sum[o<<1]+=add[o]*(mid-l+1);
        sum[o<<1|1]+=add[o]*(r-mid);
        add[o]=0;
    }
    if(x<=mid)update(o<<1,l,mid);
    if(mid<y)update(o<<1|1,mid+1,r);
    sum[o]=sum[o<<1]+sum[o<<1|1];
}
int main(){
    for(n=F(),m=F(),bt(1,0,n);m--;op=F(),x=F(),y=F(),v=F(),update(1,0,n),printf("%d\n",sum[1]));
}