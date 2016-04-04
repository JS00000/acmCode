#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if (n%2 == 1) printf("%d",0);
	else printf("%d",(n/2-1)/2);
	return 0; 
}