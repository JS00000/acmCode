#include<stdio.h>
#include<algorithm>
#include<set>
#include<string.h>
#include<vector>

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define rek(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;

const int maxn=100000+5;
int n,m,qus,tot;

int fa[maxn];
vector<int> e[maxn];
int son[maxn];
int dep[maxn];
int si[maxn];//size of tree
int ll[maxn],rr[maxn];
int up[maxn];
int own[maxn];
void dfs(int x){
    si[x]=1;
    for (int i=0;i<e[x].size();i++){
        dep[e[x][i]]=dep[x]+1;
        dfs(e[x][i]);
        si[x]+=si[e[x][i]];
        if (son[x]==0|| si[son[x]]<si[e[x][i]]) son[x]=e[x][i];
    }
}
void dfs1(int x,int y){
    tot++;
    ll[x]=tot;
    up[x]=y;
    own[tot]=x;
    if (son[x]!=0)
    {
        dfs1(son[x],y);
        for (int i=0;i<e[x].size();i++){
            if (e[x][i]==son[x]) continue;
            dfs1(e[x][i],e[x][i]);
        }
    }
    rr[x]=tot;
}
int getlca(int x,int y){
    if (dep[x]>dep[y]) return getlca(y,x);
    if (up[x]==up[y]) return x;
    if (dep[up[x]]>dep[up[y]]) return getlca(fa[up[x]],y);else return getlca(x,fa[up[y]]);

}
set<int> dfs_s[maxn];

struct seg_tree{
    int sum,lazy;
}tr[maxn*4];
void updata(int now){
    tr[now].sum=tr[now*2].sum+tr[now*2+1].sum;
}
void pushdown(int now,int l1,int r1,int l2,int r2){
    if (tr[now].lazy!=0){
        int t=tr[now].lazy;
        tr[now*2].lazy+=t;
        tr[now*2+1].lazy+=t;
        tr[now*2].sum+=t*(r1-l1+1);
        tr[now*2+1].sum+=t*(r2-l2+1);
        tr[now].lazy=0;
    }
}
void bt(int now,int l,int r){
    tr[now].sum=0;
    tr[now].lazy=0;
    if (l==r) return ;
    int mid=(l+r)/2;
    if (l<=mid) bt(now*2,l,mid);
    if (mid+1<=r)bt(now*2+1,mid+1,r);
}

void add(int now,int l,int r,int lt,int rt,int t){
    if (l>r) return;

    if (l<=lt && rt<=r){
        tr[now].lazy+=t;
        tr[now].sum+=(rt-lt+1)*t;
        return ;
    }
    int mid=(lt+rt)/2;
    pushdown(now,lt,mid,mid+1,rt);
    if (r<=mid) add(now*2,l,r,lt,mid,t);
    else if (l>mid) add(now*2+1,l,r,mid+1,rt,t);
    else {
        add(now*2,l,mid,lt,mid,t);
        add(now*2+1,mid+1,r,mid+1,rt,t);
    }
    updata(now);
}
int getsum(int now,int l,int r,int lt,int rt){
    if (l>r) return 0;
    if (l<=lt && rt<=r) return tr[now].sum;
    int mid=(lt+rt)/2;
    pushdown(now,lt,mid,mid+1,rt);
    if (r<=mid) return getsum(now*2,l,r,lt,mid);
    else if (l>mid) return getsum(now*2+1,l,r,mid+1,rt);
    else {
        return getsum(now*2,l,mid,lt,mid)+getsum(now*2+1,mid+1,r,mid+1,rt);
    }
}
void addroad(int x,int y,int t){
    if (dep[x]>dep[y]) addroad(y,x,t);
    else if (up[x]==up[y]) {add(1,ll[x],ll[y],1,n,t);}
    else if (dep[up[x]]>dep[up[y]]) {
             add(1,ll[up[x]],ll[x],1,n,t);
             addroad(fa[up[x]],y,t);
    }else {
        swap(x,y);
        add(1,ll[up[x]],ll[x],1,n,t);
        addroad(fa[up[x]],y,t);
    }
}
void change(int color,set<int>::iterator k,int t){
    int lca1,lca2;
    lca1=-1,lca2=-1;
    k++;
    set<int>::iterator k_next=k;
    {
        k--;

        if (k_next!=dfs_s[color].end()) lca1=getlca(own[*k_next],own[*k]);
    }

    if (k!=dfs_s[color].begin())
    {
        k--;
        set<int>::iterator k_last=k;
        k++;
        lca2=getlca(own[*k_last],own[*k]);
    }
//printf("%d %d %d\n",lca1,lca2,t);
    if (lca1>lca2) swap(lca1,lca2);
    if (lca1==-1 && lca2==-1){

        addroad(1,own[*k],t);
        add(1,(*k)+1,rr[own[*k]],1,n,t);
        return ;
    } else if (lca1==-1){
        addroad(lca2,own[(*k)],t);
        add(1,ll[lca2],ll[lca2],1,n,-t);
        add(1,(*k)+1,rr[own[*k]],1,n,t);
        return ;
    } else {
        if (dep[lca1]>dep[lca2]) swap(lca1,lca2);
        addroad(lca2,own[*k],t);
        add(1,ll[lca2],ll[lca2],1,n,-t);
        add(1,(*k)+1,rr[own[*k]],1,n,t);
        return ;
    }
}
int main()
{
    //freopen("j.in","r",stdin);
    //freopen("j.out","w",stdout);
    //freopen("example_j.in","r",stdin);
    //freopen("example_j.out","w",stdout);
    int T;
    scanf("%d",&T);
    rep(CASE,1,T){
        printf("CASE #%d:\n",CASE);
        scanf("%d%d%d",&n,&m,&qus);
        fa[1]=0;
        rep(i,1,n) {
            e[i].clear();
            dfs_s[i].clear();
            tot=0;
            own[i]=0;
            ll[i]=0;
            rr[i]=0;
            son[i]=0;
        }
        rep(i,2,n) {
            scanf("%d",&fa[i]);
            e[fa[i]].push_back(i);
        }
        rep(i,1,m) dfs_s[i].clear();
        tot=0;
        dep[1]=1;
        dfs(1);
        dfs1(1,1);
        bt(1,1,n);
        rep(i,1,qus){
            int t;
            scanf("%d",&t);
            if (t==1){
                int color,ee;
                scanf("%d%d",&color,&ee);
                set<int>::iterator k;
                k=dfs_s[color].lower_bound(ll[ee]);
                if (*k==ll[ee]) continue;
                bool flag=false;
                for(set<int>::iterator kk=k;ll[own[*kk]]<=rr[ee] && kk!=dfs_s[color].end();){
//printf("fuck\n");
                    flag=true;
                    change(color,kk,-1);
                    dfs_s[color].erase(kk++);
                }
                if (!flag && k!=dfs_s[color].begin()){
//printf("fuck\n");
                    k--;
                    if (rr[own[*k]]>=ll[ee]) {continue;}
                    k++;
                }
                pair< std::set< int>::iterator,bool > ret=dfs_s[color].insert(ll[ee]);
                change(color,ret.first,1);
            } else {
                int x;
                scanf("%d",&x);
                if (m>=getsum(1,ll[x],ll[x],1,n))
                printf("%d\n",m-getsum(1,ll[x],ll[x],1,n)); else{
                    printf("%d\n",CASE);
                    printf("%d\n",x);
                    while (1);
                }
            }
        }
    }
    return 0;
}
