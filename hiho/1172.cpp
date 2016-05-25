#include <cstdio>
#define maxn 10001

int main(int argc, char const *argv[])
{
	int n, ret = 0;
	int a[maxn];
	char c;
	scanf("%d", &n);
	getchar();
	int j = 0;
	for (int i = 1; i <= n; ++i)
	{
		c = getchar();
		if (c == 'H') a[j++] = i;
	}
	for (int i = 0; i < j; ++i) ret ^= a[i];
	if (ret == 0) printf("Bob\n");
	else printf("Alice\n");
	return 0;
}