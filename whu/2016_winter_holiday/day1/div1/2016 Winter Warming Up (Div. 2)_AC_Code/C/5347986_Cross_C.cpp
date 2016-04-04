#include<cstdio>
#include<cstring>
using namespace std;
int max(int a,int b){
	if(a>b)return a;
	return b;
}
int p[100001];int n;
int f[100001];
int main(){
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	int sol=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n;i++)
		if(f[p[i]-1]>0)f[p[i]]=f[p[i]-1];
			else	f[p[i]]=p[i];
	for(int i=1;i<=n;i++)
		sol=max(sol,i-f[i]+1);
	printf("%d",n-sol);
	return 0;
}