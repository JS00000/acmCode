#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(n%2==1)
		puts("0");
	else printf("%d\n",n/4-1+(n/2)%2);
}