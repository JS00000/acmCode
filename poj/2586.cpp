#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;

int main()
{
	ll s, d, ans;
	while(~scanf("%lld%lld", &s, &d))
	{
		if (4*s < d) ans = 10*s - 2*d;
		else if (3*s < 2*d) ans = 8*s - 4*d;
		else if (2*s < 3*d) ans = 6*s - 6*d;
		else if (s < 4*d) ans = 3*s - 9*d;
		else ans = -1;
		if (ans <= 0) printf("Deficit\n");
		else printf("%lld\n", ans);
	}
	return 0;
}
