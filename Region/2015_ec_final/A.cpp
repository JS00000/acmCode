#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int main()
{
	int T, kase = 0;
	scanf("%d", &T);
	while(T--)
	{
		unsigned long long n, l = 1, r = 1e10, m, x;
		scanf("%llu", &n);
		while(l <= r)
		{
			m = (l+r)/2;
			x = m * (m+1) / 2;
			if (x <= n) l = m+1;
			else if (x > n) r = m-1;
		}
		printf("Case #%d: %llu\n", ++kase, (l-1)*l/2);
	}
	return 0;
}
