// J
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

const int N=1010000;
int n,_;
bool f[N],g[N],preg[N],preg2[N];
char s[N];
int ret[N],ret2[N],cnt[N],cnt2[N];
void gao(bool *g,int *ret,int n) {
	rep(i,1,n+1) ret[i]=1<<30;
	int fo=n+1,lo=-1;
	rep(i,1,n+1) {
		if (g[i]) {
			if (fo==n+1) fo=i;
			lo=i;
		}
	}
	if (fo>lo) {
		rep(i,1,n+1) ret[i]=0;
		return;
	}
	rep(i,1,n+1) {
		preg[i]=preg[i-1]^g[i]^1;
		preg2[i]=preg2[i-1]^g[i];
		cnt[i]=cnt[i-1]+preg[i];
		cnt2[i]=cnt2[i-1]+preg2[i];
	}
	rep(i,0,lo+1) {
		if (i<=fo) {
			int fw=i,lw=lo;
			if (i==lo) {
				ret[i]=min(ret[i],3);
				continue;
			}
			int ans=lw-fw;
			if (preg[fw-1]) ans+=2*(cnt[lw-1]-cnt[fw-1]);
			else ans+=2*(lw-fw-cnt[lw-1]+cnt[fw-1]);
			if (preg[lw-1]^preg[fw-1]^1) ans--;
			ret[i]=min(ret[i],ans);
		} else {
			int fw=fo,lw=lo;
			int ans=i-fo+lw-fw;
			if (preg2[fw-1]) ans+=2*(cnt2[i-1]-cnt2[fw-1]);
			else ans+=2*(i-fw-cnt2[i-1]+cnt2[fw-1]);
			int x=preg2[i-1]^preg2[fw-1]^1;
			if (x==preg[i-1]) ans+=2*(cnt[lw-1]-cnt[i-1]);
			else ans+=2*(lw-i-cnt[lw-1]+cnt[i-1]);
			if (x^preg[i-1]^preg[lw-1]) ans--;
			ret[i]=min(ret[i],ans);
		}
	}
}
void solve() {
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n+1) g[i]=(s[i]=='1');
	gao(g,ret,n);
	reverse(g+1,g+n+1);
	gao(g,ret2,n);
	ll ans=0;
	rep(i,1,n+1) {
		ret[i]=min(ret[i],ret2[n+1-i]);
		ans=(ans+(ll)i*ret[i])%mod;
	}
	printf("%lld\n",ans);
}
int main() {
	for (scanf("%d",&_);_;_--) solve();
}
