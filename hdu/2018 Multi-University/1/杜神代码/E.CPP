// E
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
struct tSPnode {
	int ty,u,v,w;
	ll dp[2][2];
	ll way[2][2];
	tSPnode *l,*r;
}tpool[N*2],*tcur,*E[N];
int dq[N],inq[N],_,n,m,u,v,w;
map<int,tSPnode*> se[N];
tSPnode* newtnode(int u,int v,int w=0) {
	tSPnode* p=tcur++;
	p->ty=-2; p->u=u; p->v=v; p->l=p->r=0; p->w=w;
	memset(p->dp,0xee,sizeof(p->dp));
	memset(p->way,0,sizeof(p->way));
	return p;
}
void insertSP(int u,int v,tSPnode *c) {
	if (se[u].count(v)) {
		tSPnode *p=newtnode(u,v);
		p->ty=-1; // par
		p->l=se[u][v];
		p->r=c;
		se[u][v]=se[v][u]=p;
	} else {
		se[u][v]=se[v][u]=c;
	}
}

void gao(tSPnode *Rt) {
	if (Rt->ty==-2) {
		Rt->dp[0][0]=0;
		Rt->way[0][0]=1;
		Rt->dp[1][1]=Rt->w;
		Rt->way[1][1]=1;
	} else if (Rt->ty==-1) {
		if (Rt->l->u!=Rt->u) swap(Rt->l->u,Rt->l->v);
		if (Rt->r->v!=Rt->v) swap(Rt->r->u,Rt->r->v);
		assert(Rt->l->u==Rt->u);
		assert(Rt->r->u==Rt->u);
		assert(Rt->l->v==Rt->v);
		assert(Rt->r->v==Rt->v);
		gao(Rt->l); gao(Rt->r);
		rep(pl,0,3) rep(pr,0,3) {
			int fl=(pl==1),gl=(pl==2),fr=(pr==1),gr=(pr==2);
			if (Rt->dp[fl+gl][fr+gr]<Rt->l->dp[fl][fr]+Rt->r->dp[gl][gr]) {
				Rt->dp[fl+gl][fr+gr]=Rt->l->dp[fl][fr]+Rt->r->dp[gl][gr];
				Rt->way[fl+gl][fr+gr]=0;
			}
			if (Rt->dp[fl+gl][fr+gr]==Rt->l->dp[fl][fr]+Rt->r->dp[gl][gr]) {
				(Rt->way[fl+gl][fr+gr]+=Rt->l->way[fl][fr]*Rt->r->way[gl][gr])%=mod;
			}
		}
	} else {
		if (Rt->l->u!=Rt->u&&Rt->l->v!=Rt->u) swap(Rt->l,Rt->r);
		if (Rt->l->u!=Rt->u) swap(Rt->l->u,Rt->l->v);
		if (Rt->r->v!=Rt->v) swap(Rt->r->u,Rt->r->v);
//		printf("%d %d %d %d %d %d\n",Rt->u,Rt->v,Rt->l->u,Rt->l->v,Rt->r->u,Rt->r->v);
		assert(Rt->l->v==Rt->r->u);
		gao(Rt->l); gao(Rt->r);
		rep(fl,0,2) rep(gr,0,2) rep(fmid,0,3) {
			int gl=(fmid==1),fr=(fmid==2);
			if (Rt->dp[fl][gr]<Rt->l->dp[fl][fr]+Rt->r->dp[gl][gr]) {
				Rt->dp[fl][gr]=Rt->l->dp[fl][fr]+Rt->r->dp[gl][gr];
				Rt->way[fl][gr]=0;
			}
			if (Rt->dp[fl][gr]==Rt->l->dp[fl][fr]+Rt->r->dp[gl][gr]) {
				(Rt->way[fl][gr]+=Rt->l->way[fl][fr]*Rt->r->way[gl][gr])%=mod;
			}
		}
	}
//	printf("%d %d %d\n",Rt->u,Rt->v,Rt->ty);
//	printf("%lld %lld %lld %lld\n",Rt->dp[0][0],Rt->dp[0][1],Rt->dp[1][0],Rt->dp[1][1]);
}
void parse() {
	rep(i,0,n) se[i].clear();
	rep(i,0,m) {
		int u=E[i]->u,v=E[i]->v;
		insertSP(u,v,E[i]);
	}
	int tot=0;
	rep(u,0,n) {
		inq[u]=0;
		if (SZ(se[u])==2) dq[tot++]=u,inq[u]=1;
	}
	VI rv;
	rep(i,0,tot) {
		int u=dq[i];
		if (SZ(se[u])!=2) { rv.pb(u); continue;}
		auto it=se[u].begin(),nit=it;
		++it;
		int p=it->fi,q=nit->fi;
		tSPnode *s=it->se,*t=nit->se;
		se[p].erase(u); se[q].erase(u);
		tSPnode *r=newtnode(p,q); r->ty=u;
		r->l=s, r->r=t;
		insertSP(p,q,r);
		if (!inq[p]&&SZ(se[p])==2) dq[tot++]=p,inq[p]=1;
		if (!inq[q]&&SZ(se[q])==2) dq[tot++]=q,inq[q]=1;
	}
	rep(i,0,n) if (!inq[i]) rv.pb(i);
	assert(SZ(rv)==2);
	tSPnode *Rt=se[rv[0]][rv[1]];
	gao(Rt);
	ll ret=-1,way=0;
	rep(i,0,2) rep(j,0,2) {
		if (ret<Rt->dp[i][j]) {
			ret=Rt->dp[i][j];
			way=0;
		}
		if (Rt->dp[i][j]==ret) way=(way+Rt->way[i][j])%mod;
	}
	printf("%lld %lld\n",ret,way);
}

void gao() {
	scanf("%d%d",&n,&m);
	tcur=tpool;
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&w);
		--u; --v;
		E[i]=newtnode(u,v,w);
	}
	parse();
}

int main() {
	for (scanf("%d",&_);_;_--) gao();
}
