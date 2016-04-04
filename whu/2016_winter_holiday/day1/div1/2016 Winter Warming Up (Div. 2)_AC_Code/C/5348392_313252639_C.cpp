#include<cstdio>
#include<algorithm>
using namespace std;
int a[100100],d[100100],n;
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
		d[a[i]]=1;
		if (d[a[i]-1]) d[a[i]]=d[a[i]-1]+1;
	}	
		
	int maxn=0;
	for (int i=0;i<n;i++)
		maxn=max(maxn,d[a[i]]);
	printf("%d",n-maxn);
	return 0;
}