#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 207
using namespace std;
int a[maxn];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, i, j, t, ans = 0;
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		for (int k = 0; k < n; k++)
		{
			scanf("%d%d", &i, &j);
			i--, j--;
			if (i > j) t=i, i=j, j=t;
			for (int l = i>>1 ; l <= j>>1; l++) a[l]++;
		}
		for (int k = 0; k < 200; k++) if (ans < a[k]) ans = a[k];
		printf("%d\n", ans*10);
	}
}
