#include <cstdio>
int main()
{
	char c;
	int k = 1, sum = 0, temp;
	while(c = getchar() , c != '#')
	{
		if (c == '\n')
		{
			printf("%d\n", sum);
			sum = 0, k = 1;
			continue;
		}
		temp = c - 'A' + 1;
		if (c == ' ') temp = 0;
		sum += temp * k++;
	}
	return 0;
}
