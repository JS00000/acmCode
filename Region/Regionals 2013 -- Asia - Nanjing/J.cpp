#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long


int main()
{
	LL sum, ans;
	LL a[3];
	while(~scanf("%lld%lld%lld", a, a+1, a+2))
	{
		sort(a, a+3);
		sum = a[0] + a[1] + a[2];
		if (a[2] == 0){
			printf("0\n");
		}else if (a[2] == 1){
			if (sum == 1) printf("0\n");
			else if (sum == 2) printf("1\n");
			else printf("3\n");
		}else if (a[1] == 0){
			printf("%lld\n", 1+(a[2]-2)*2);
		}else if (a[1] == 1){
			if (a[0] == 0) printf("%lld\n", 3+(a[2]-2)*3);
			else if (a[0] == 1) printf("%lld\n", 6+(a[2]-2)*4);
		}else if (a[0] == 0){
			printf("%lld\n", 6+(a[1]+a[2]-4)*4);
		}else if (a[0] == 1){
			printf("%lld\n", 10+(a[1]+a[2]-4)*5);
		}else{
			printf("%lld\n", 15+(a[0]+a[1]+a[2]-6)*6);
		}
	}
	return 0;
}
