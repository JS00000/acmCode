#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,m,q,l,r,k;
	char st[100001];
	while (scanf("%d%d%d", &n, &m, &q) == 3)
	{
		getchar();
		fgets(st, n + 1, stdin);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d", &l, &r);
			reverse(st+l-1, st+r);
		}
		for (int i = 0; i < q; ++i)
		{
			scanf("%d",&k);
			putchar(st[k-1]);
		}
		putchar('\n');
	}
	return 0;
}
