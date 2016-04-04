#include "cstdio"

int main(int argc, char const *argv[])
{
	double n;
	while(~scanf("%lf",&n))
	{
		printf("%ld\n\n", long(n*(n+1)/2));
	}
}
