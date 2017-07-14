#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdint.h>
#include <inttypes.h>
#include <algorithm>
using namespace std;
typedef int64_t ll;
ll n,l,r,q,a;
ll lowbit(ll x)
{
	return x&(-x);
}
ll lowbit_sum(ll x)
{
	ll ans = 0;
    for(int k = 0; (1ll<<k) <= x; k++)
    {
        ans += ((x>>(k+1)) + !!((1ll<<k) & x)) * (1ll<<k);
    }
	return ans;
}
int main()
{
	for (int i = 0; i < 20; i++) printf("%d: %lld %lld\n", i, lowbit(i), lowbit_sum(i));
	return 0;
}
