#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

typedef long long ll;

void Euild(ll a, ll b, ll &x, ll &y)  // x 是 a 关于 b 的乘法逆元
{
    if(0 == b){
        x = 1, y = 0;
        return ;
    }
    Euild(b, a%b, x, y);
    ll flag = x;
    x = y;
    y = flag - a/b * y;
}

// p[i]: 长度为2*i+1不通的概率

// p[0] = 1/2;
// p[i] = (1-(1/2)^(2*i+1))^(A(l-1,i)*A(r-1,i))

// ans = 1*(1-p[0]) + 3*(1-p[1])*p[0] + 5*(1-p[2])*p[0]*p[1] + ... 

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		ll l, r, p;
		scanf("%d%d%d", &l, &r, &p);
		ll ans = 0;
		for (int i = 0; i < min(l, r); i++) {
			
		}

		ll x, y;
		Euild(16, 772001, x, y);
		printf("%lld\n", (((x + 772001) % 772001) * 11) % 772001);
	}
	return 0;
}

