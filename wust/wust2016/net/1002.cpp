#include <cstdio>

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		if (n==1 || n==2)
		{
			printf("1\n");
			continue;
		}
		unsigned long long ans = 1;
		for (int i = 3; i < n; ++i)
		{
			ans *= i;
		}
		printf("%llu\n", ans);
	}
	return 0;
}