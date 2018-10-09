// D
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

const int N=101000;
int _,n,m,pre[N],l,r,ret[N];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&m);
		rep(i,1,n+1) pre[i]=i;
		rep(i,0,m) {
			scanf("%d%d",&l,&r);
			pre[r]=min(pre[r],l);
		}
		per(i,1,n) pre[i]=min(pre[i],pre[i+1]);
		int pl=1;
		set<int> val;
		rep(i,1,n+1) val.insert(i);
		rep(i,1,n+1) {
			while (pl<pre[i]) {
				val.insert(ret[pl]);
				pl++;
			}
			ret[i]=*val.begin();
			val.erase(ret[i]);
		}
		rep(i,1,n+1) printf("%d%c",ret[i]," \n"[i==n]);
	}
}
