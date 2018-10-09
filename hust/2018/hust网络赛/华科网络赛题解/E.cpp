#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
const int maxm = 20;
const int max_state = 2e6;
struct PARCEL{
	int p,value;
}parcel[maxn+10];
bool cmp(PARCEL x,PARCEL y) {
	return x.p>y.p;
}
int suffix[maxm+10];
int get_state(int a[],int n) {
	int state=0;
	for(int i=0;i<n;i++)
		state+=suffix[i+1]*a[i];
	return state;
}
double dp[max_state+10];
double dfs(int a[],int n,int m,double cnt) {
	int state=get_state(a,m);
	if(dp[state]!=0) return dp[state];
	double ans=cnt;
	for(int i=0;i<m;i++) {
		if(a[i]==0) ans+=(double)parcel[i].value/n;
		else {
			a[i]--;
			ans+=max((double)parcel[i].value,dfs(a,n,m,cnt))/n;
			a[i]++;
		}
	}
	return dp[state]=ans;
}
int a[maxm+10];
void work() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&parcel[i].p,&parcel[i].value);
	sort(parcel,parcel+n,cmp);
	int m=0;
	while(parcel[m].p) m++;
	for(int i=0;i<m;i++)
		a[i]=parcel[i].p;
	suffix[m]=1;
	for(int i=m-1;i>=0;i--) suffix[i]=suffix[i+1]*(parcel[i].p+1);
	for(int i=0;i<n;i++)
		dp[0]+=(double)parcel[i].value/n;
	double cnt=0;
	for(int i=m;i<n;i++)
		cnt+=(double)parcel[i].value/n;
	printf("%lf\n",dfs(a,n,m,cnt));
	return ;
}
int main() {
	work();
	return 0;
}
