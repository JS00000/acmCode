#include <iostream>
#include <cstdio>

using namespace std;	

typedef long long LL;

int main(int argc, char const *argv[])
{
	LL t;
	int a,b,c,d;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d %d\n", c, b + d);
		printf("%d %d\n", a, b + d);
	}
	return 0;
}