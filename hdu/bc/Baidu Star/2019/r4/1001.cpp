#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll n, a, b, ans;

double df(ll x) {
	if (x == 1) return b;
	else if (x & 1) {
		return double(x-1)*x*x*a+double(x)*x*x*b;
	} else {
		double normal = double(x-1)*x*x*a + double(x)*x*x*b;
		double Strassen = 18.0*x*x/2/2*a + 7.0*df(x/2);
		if (normal < Strassen) {
			return normal;
		} else {
			return Strassen;
		}
	}
}

ll f(ll x) {
	if (x == 1) return b;
	else if (x & 1) {
		return ((x-1)*x%mod*x%mod*a%mod+x*x%mod*x%mod*b%mod)%mod;
	} else {
		double normal = double(x-1)*x*x*a + double(x)*x*x*b;
		double Strassen = 18.0*x*x/2/2*a + 7.0*df(x/2);
		if (normal < Strassen) {
			return ((x-1)*x%mod*x%mod*a%mod+x*x%mod*x%mod*b%mod)%mod;
		} else {
			return (18*(x/2)%mod*(x/2)%mod*a%mod+7*f(x/2)%mod)%mod;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld", &n, &a, &b);
		printf("%lld\n", f(n));
	}
	return 0;
}
