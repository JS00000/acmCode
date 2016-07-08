#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if (n % 2 != 0)
	{
		printf("0\n");
	}
	else
	{
		n /= 2;
		printf("%d\n", (n - 1) / 2);
	}
	return 0;
}