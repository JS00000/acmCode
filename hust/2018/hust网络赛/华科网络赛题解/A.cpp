#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
struct E{
	int v, w, n;
}G[N<<1];
int cnt, point[N];
void adde(int u, int v, int w = 0){
	G[++cnt]=(E){v,w,point[u]},point[u]=cnt;
	G[++cnt]=(E){u,w,point[v]},point[v]=cnt;
}
void Ginit(){
	cnt = 0;
	memset(point,0,sizeof(point));
}
int n, k;
ll now[2][N];
ll ans;
void solve(int u, int f){
	now[0][u] = 1, now[1][u] = 0;
	ans += k==0;
	for(int i = point[u];i;i=G[i].n){
		int v = G[i].v;
		if(v == f)continue;
		solve(v,u);
		for(int j = 0;j < 2; ++j)ans += 2*now[j][u]*now[j^k^1][v];
		for(int j = 0;j < 2; ++j)now[j][u] += now[j^1][v];
	}
}
int main(){
	int Case, u, v;
	scanf("%d", &Case);
	while(Case--){
		scanf("%d", &n);
		k = n&1;
		Ginit();
		for(int i = 1;i < n; ++i){
			scanf("%d %d", &u, &v);
			adde(u,v);
		}
		ans = 0;
		solve(1,0);
		printf("%lld\n", ans*n);
	}
	return 0;
}
