#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;
typedef long long ll;
ll a[maxn], n, k, m;

int main()
{
	int T, kase = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld", &n, &k);
		ll sum = 0, ans = 0 , s = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", a+i);
			sum += a[i];
		}
		if (sum % k != 0) 
		{
			printf("Case #%d: -1\n", ++kase);
			continue;
		}
		m = sum / k;
		int j = 0;
		for (int i = 0; i < n; ++i)
		{
			s += a[i];
			if (s >= m)
			{
				int t = i - j + (s-1) / m;
				ans += t;
				s = s % m;
				if (s == 0) j = i+1;
				else j = i;
			}
		}
		printf("Case #%d: %lld\n", ++kase, ans);
	}
	return 0;
}
