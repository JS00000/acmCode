#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int a[N];
int main()
{
	int n,MinNum=(1ll<<31)-1,len=0,ans=0;
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		MinNum=min(MinNum,a[i]);
	}
	for(int i=1;i<=n+n-1;++i)
	{
		int j=i;
		if(i>n) j=i-n;
		if(a[j]>MinNum)
		{
			++len;
		}
		else
		{
			ans=max(ans,len);len=0;
		}
	}
	printf("%I64d\n",(long long)MinNum*n+ans);
}
		