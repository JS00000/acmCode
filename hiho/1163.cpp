#include <cstdio>
#include <cmath>
#include <algorithm>
#define maxn 101

int main(int argc, char const *argv[])
{
	int n, ret = 0;
	int a[maxn];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a+i);
	for (int i = 0; i < n; ++i) ret ^= a[i];
	if (ret == 0) printf("Bob\n");
	else printf("Alice\n");
	return 0;
}