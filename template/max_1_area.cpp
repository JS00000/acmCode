#include <cstdio>
#define N 1001
int n,m,i,j,ans,l[N],r[N],h[N],lmax,rmax,a[N][N];
int main()
{
	for(scanf("%d%d",&n,&m),i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",&a[i][j]); for(i=1;i<=m;i++)l[i]=1,r[i]=m;
	for(i=1;i<=n;i++)
	{
		for(lmax=j=1;j<=m;j++)
			if(a[i][j]){
				h[j]++;
				if(lmax>l[j])l[j]=lmax;
			}
			else h[j]=0,l[j]=1,r[j]=m,lmax=j+1; 
		for(rmax=j=m;j;j--)
			if(a[i][j])
			{
				if(rmax<r[j])r[j]=rmax;
				if((r[j]-l[j]+1)*h[j]>ans)ans=(r[j]-l[j]+1)*h[j]; 
			}
			else rmax=j-1;
	}
	printf("%d",ans);
}
