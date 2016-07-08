#include<cstdio>
using namespace std;
const long long maxnum=1e18;
long long l,r,k;
int main()
{
	scanf("%I64d%I64d%I64d",&l,&r,&k);
	long long tmp=1,flag=0;
	while (tmp<l) if (tmp <= maxnum / k) tmp*=k;
					else break;
	while (tmp>=l && tmp<=r)
	{

		if (tmp>maxnum / k) break;
		else {
			flag=1;
			printf("%I64d ",tmp);
			tmp *= k;
		}
	}
	if (tmp >= l && tmp <= r){
		flag= 1;
		printf("%I64d", tmp);
	}
	if (flag==0) printf("-1"); 
	return 0;
}