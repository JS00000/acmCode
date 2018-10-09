#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1e5+10;

int n,k,f;
int z[maxn],x[maxn],y[maxn];

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]),y[i]=x[i];
		
	for(int i=1;i<=k&&i<=n;i++)
	{
		z[0]=0;
		for(int j=i;j<=n;j+=k)
			z[++z[0]]=x[j];
		sort(z+1,z+1+z[0]);
		z[0]=0;
		for(int j=i;j<=n;j+=k)
			x[j]=z[++z[0]];
	}
		
	sort(y+1,y+1+n);
	for(int i=1;i<=n;i++)
		if(y[i]!=x[i]){f=1;printf("%d",i);break;}
	if(!f)printf("-1");
	
	return 0;
}
