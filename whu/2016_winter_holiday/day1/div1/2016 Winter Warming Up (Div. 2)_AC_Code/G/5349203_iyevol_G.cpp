#include<cstdio>
#include<algorithm>
using namespace std;
long long l,r,k;
int main()
{
	while(scanf("%I64d%I64d%I64d",&l,&r,&k)!=EOF)
	{
		bool used=0;
		long long t=1;
		while(t<=r)
		{
			if(t>=l)
			{
				used=1;
				printf("%I64d",t);
				if(t<=r/k) printf(" ");
				else break;
			}	
			if(t>r/k) break;
			t*=k;
		}
		if(!used) printf("-1");
		printf("\n");
	}
}
		