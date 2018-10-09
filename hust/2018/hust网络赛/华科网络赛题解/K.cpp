#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn=1e5+10;

long long l,r,mid;
int n,k;
int d[maxn];

bool check(long long t)
{
	int tot=0;
	long long cnt=0;
	for(int i=1;i<n;i++)
	{
		if(d[i]>t)return 0;
		if(cnt+d[i]>t)tot++,cnt=d[i];
		else cnt+=d[i];
	}
	return tot<=(k-1);
}

int main()
{
	scanf("%d%d",&n,&k); 
	for(int i=1;i<n;i++)
		scanf("%d",&d[i]),r+=d[i];
	
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	
	printf("%lld",r);

	return 0;
}
