// 曼哈顿凸包
#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,r,t=0,q[100010],A,B,C,D;long long ans;struct P{int x,y;}a[100010];
bool cmp(P a,P b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int main(){
	A=C=~0U>>1,B=D=-A;
	for(scanf("%d",&n),i=1;i<=n;i++){
	    scanf("%d%d",&a[i].x,&a[i].y);
	    A=min(A,a[i].x);
	    B=max(B,a[i].x);
	    C=min(C,a[i].y);
	    D=max(D,a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)if(!t||a[i].y>r)r=a[i].y,q[++t]=i;
	for(i=q[r=t]+1;i<=n;q[++t]=i++)while(t>r&&a[i].y>=a[q[t]].y)t--;
	for(i=2;i<=t;i++)ans+=1LL*min(a[q[i-1]].y,a[q[i]].y)*(a[q[i]].x-a[q[i-1]].x);
	for(t=0,i=1;i<=n;i++)if(!t||a[i].y<r)r=a[i].y,q[++t]=i;
	for(i=q[r=t]+1;i<=n;q[++t]=i++)while(t>r&&a[i].y<=a[q[t]].y)t--;
	for(i=2;i<=t;i++)ans-=1LL*max(a[q[i-1]].y,a[q[i]].y)*(a[q[i]].x-a[q[i-1]].x);
	printf("%lld\n%lld",2LL*B+2LL*D-2LL*A-2LL*C,ans);
}
