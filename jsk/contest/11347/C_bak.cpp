#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=300100;
const int M=9001000;
int n,m,x,size,l,r,k,rt[N];
int sz[M],ls[M],rs[M];

void ins(int &rt,int pre,int l,int r,int k){
    rt=++size;sz[rt]=sz[pre]+1;
    ls[rt]=ls[pre];rs[rt]=rs[pre];
    if (l==r) return;int mid=(l+r)>>1;
    if (k<=mid)
        ins(ls[rt],ls[pre],l,mid,k); else
        ins(rs[rt],rs[pre],mid+1,r,k);
}

int query(int lrt,int rrt,int l,int r,int k){
    if (sz[rrt]-sz[lrt]<=k) return -1;
    if (l==r) return l;int mid=(l+r)>>1;
    int t=query(ls[lrt],ls[rrt],l,mid,k);
    if (t>0) return t;
    return query(rs[lrt],rs[rrt],mid+1,r,k);
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&x);
        ins(rt[i],rt[i-1],1,n,x);
    }
    while (m--){
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",query(rt[l-1],rt[r],1,n,(r-l+1)/k));
    }
}