#include <iostream>

typedef long long LL;
using namespace std;

LL A,B;
LL plu[64];
LL sum[64];

LL solu(LL x)
{
	LL t = 1, ret = 0;
	int k = 0, j = 0;
	while(t*2<=x)
	{
		t*=2;
		k++;
	}
	for (int i = 0; i < k; ++i)
	{
		ret+=sum[i];
	}
	LL dif = x - t;
	while(dif)
	{
		t = 1;
		k = 0;
		while(t*2<=dif)
		{
			t*=2;
			k++;
		}
		ret += sum[k] + plu[k+1]*j;
		j++;
		dif -= t;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	plu[0] = 1;
	sum[0] = 1;
	plu[1] = 1;
	sum[1] = 3;
	for (int i = 2; i < 64; ++i)
	{
		plu[i] = plu[i-1]*2;
		sum[i] = sum[i-1]*2 + plu[i];
	}
	while(scanf("%lld%lld",&A,&B)!=EOF)
	{
		LL ans;
		ans = solu(B+1)-solu(A);
		cout << ans << endl;
	}
	return 0;
}
