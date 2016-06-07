#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

int t, n, k;
int a[50007];
LL f[50007];
LL f2[50007];
double temp, center, fc, ans, sum1, sum2;

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i)
			scanf("%d", a+i);
		if (n == k)
		{
			puts("0");
			continue;
		}
		sort(a, a+n);
		f[0] = 0;
		f2[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			f[i] = f[i-1] + a[i-1];
			f2[i] = f2[i-1] + LL(a[i-1])*a[i-1];
		}
		for (int i = 1; i <= n; ++i)
		ans = 1e18;
		for (int i = 0; i <= k; ++i)
		{
			sum1 = f[i+n-k] - f[i];
			sum2 = f2[i+n-k] - f2[i];
			fc = sum2 - sum1*sum1/(n-k);
			if (fc < ans) ans = fc;
		}
		printf("%.12lf\n", ans);
	}
	return 0;
}
