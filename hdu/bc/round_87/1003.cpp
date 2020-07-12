#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 1000017

using namespace std;

int n, m, temp, ans, pa[maxn], pb[maxn], a[maxn], b[maxn];


int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		ans = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", a+i);
			pa[a[i]] = pa[a[i]-1] + 1;
		}
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &b[i]);
			pb[b[i]] = pb[b[i]-1] + 1;
			ans = max(ans, min(pa[b[i]], pb[b[i]]));
		}
		printf("%d\n", ans);
		for (int i = 0; i < n; ++i)
			pa[a[i]] = 0;
		for (int i = 0; i < m; ++i)
			pb[b[i]] = 0;
	}
	return 0;
}