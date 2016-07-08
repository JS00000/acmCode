#include<cstdio>
using namespace std;
const int N=100005;
int p[N],ans[N],out;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",p+i);
		ans[p[i]]=ans[p[i]-1]+1;
		if(ans[p[i]]>out) out=ans[p[i]];
	}
		
	
	printf("%d\n",n-out);
		
}