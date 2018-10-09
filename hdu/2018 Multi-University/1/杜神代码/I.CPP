// I
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
const ll mod1=1000000007;
const ll mod2=1000000009;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int L=601000,N=101000;;
char s[L];
int ss[L],sa[L],rk[L],bp[N],mg[N];

struct substr {
	int id,l,len;
};
typedef pair<int,int> hashv;
vector<substr> g[N],sg[N];
hashv base(13331,23333);
hashv hv[L],pw[L];

int n,m,u,v,_;

hashv operator + (hashv a,hashv b) {
	int c1=a.fi+b.fi,c2=a.se+b.se;
	if (c1>=mod1) c1-=mod1;
	if (c2>=mod2) c2-=mod2;
	return mp(c1,c2);
}

hashv operator - (hashv a,hashv b) {
	int c1=a.fi-b.fi,c2=a.se-b.se;
	if (c1<0) c1+=mod1;
	if (c2<0) c2+=mod2;
	return mp(c1,c2);
}

hashv operator * (hashv a,hashv b) {
	return mp(1ll*a.fi*b.fi%mod1,1ll*a.se*b.se%mod2);
}

vector<substr> lyndon(char *s,int n,int id,int &mg){
	int k=0;
	mg=0;
	vector<substr> g;
	while (k<n) {
		int i=k+1,j=k+2;
		while (1) {
			if (j==n+1||s[j-1]<s[i-1]) {
				int mul=0,b=k,l=j-i;
				while (k<i) {
					mul++;
					k+=j-i;
				}
				g.pb((substr){id,b,l});
				mg=max(mg,l);
				break;
			} else {
				if (s[j-1]>s[i-1]) {
					i=k+1;
				} else {
					i=i+1;
				}
				j=j+1;
			}
		}
	}
	return g;
}

void buildSA(int *s,int *sa,int *rk,int n,int m=128) {
	static int X[L],Y[L],c[L];
	int *x=X,*y=Y;
	rep(i,0,m) c[i]=0;
	rep(i,0,n) c[x[i]=s[i]]++;
	rep(i,1,m) c[i]+=c[i-1];
	per(i,0,n) sa[--c[x[i]]]=i;
	for (int k=1;k<n;k<<=1) {
		int p=0;
		per(i,n-k,n) y[p++]=i;
		rep(i,0,n) if (sa[i]>=k) y[p++]=sa[i]-k;
		rep(i,0,m) c[i]=0;
		rep(i,0,n) c[x[y[i]]]++;
		rep(i,1,m) c[i]+=c[i-1];
		per(i,0,n) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1; x[sa[0]]=0; y[n]=-1;
		rep(i,1,n) x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&
		y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
		if (p==n) break;
		m=p;
	}
	rep(i,0,n)rk[sa[i]]=i;
	rep(i,0,n) hv[i+1]=hv[i]*base+mp(s[i],s[i]);
}

int pos(const substr &a) {
	return bp[a.id]+a.l;
}

hashv query(const substr &a) {
	int posl=bp[a.id]+a.l,posr=bp[a.id]+a.l+a.len;
	return hv[posr]-hv[posl]*pw[posr-posl];
}
int cmp(const substr& a,const substr& b) {
	int l=min(a.len,b.len);
	auto p1=query((substr){a.id,a.l,l}),p2=query((substr){b.id,b.l,l});
	if (p1==p2) {
		if (a.len<b.len) return -1;
		else if (a.len==b.len) return 0;
		else return 1;
	}
	return rk[pos(a)]<rk[pos(b)]?-1:1;
}

substr tmpa[20],tmpb[20];
int tmp[20];
int cmp(substr* a,int p1,substr* b,int p2) {
	int q1=0,q2=0;
	while (q1<p1&&q2<p2) {
		if (a[q1].len==b[q2].len) {
			int r=cmp(a[q1],b[q2]);
			if (r==0) q1++,q2++;
			else return r;
		} else if (a[q1].len<b[q2].len) {
			substr c=b[q2];
			c.len=a[q1].len;
			int r=cmp(a[q1],c);
			if (r!=0) return r;
			else {
				b[q2].l+=a[q1].len;
				b[q2].len-=a[q1].len;
				q1++;
			}
		} else {
			substr c=a[q1];
			c.len=b[q2].len;
			int r=cmp(c,b[q2]);
			if (r!=0) return r;
			else {
				a[q1].l+=b[q2].len;
				a[q1].len-=b[q2].len;
				q2++;
			}			
		}
	}
	if (q1==p1&&q2==p2) return 0;
	if (q1==p1) return -1;
	else return 1;
}

substr t1[10],t2[10];
void solve() {
	scanf("%d%d",&n,&m);
	int cur=0;
	rep(i,0,n) {
		scanf("%s",s);
		bp[i]=cur;
		int len=strlen(s);
		rep(j,0,len) ss[cur++]=s[j];
		ss[cur++]=129+i;
		g[i]=lyndon(s,len,i,mg[i]);
		sg[i].clear();
		for (auto p:g[i]) sg[i].pb((substr){i,p.l,len-p.l});
	}
	buildSA(ss,sa,rk,cur,130+n);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		--u; --v;
		int r=cmp(g[u].back(),g[v][0]);
		if (r>=0) {
			printf("%d\n",max(mg[u],mg[v]));
		} else {
			int l=-1,r=SZ(g[u])-1;
			substr sr=sg[v][0];
			while (l+1<r) {
				int md=(l+r)>>1;
				t1[0]=sg[u][md]; t1[1]=sr;
				t2[0]=sg[u][md+1]; t2[1]=sr;
				if (cmp(t1,2,t2,2)==-1) r=md; else l=md;
			}
			int pl=0,pr=SZ(g[v]);
			while (pl+1<pr) {
				int md=(pl+pr)>>1;
				t1[0]=sg[v][md];
				t2[0]=sg[u][r]; t2[1]=sr;
				if (cmp(t1,1,t2,2)==1) pl=md; else pr=md;
			}
			int ans=sg[u][r].len;
			if (pl==SZ(sg[v])-1) ans+=sg[v][0].len;
			else ans+=sg[v][pl+1].l;
			printf("%d\n",max(ans,max(mg[u],mg[v])));
		}
	}
}
int main() {
	pw[0]=mp(1,1);
	rep(i,1,600001) pw[i]=pw[i-1]*base;
	for (scanf("%d",&_);_;_--) solve();
}
