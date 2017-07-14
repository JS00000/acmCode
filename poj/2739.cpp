#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 10007
using namespace std;

int tot = 0;
int prime[maxn+9];
int prime_sum[maxn+9];
bool mark[maxn+9];
void prime_init()
{
    memset(mark, 0, sizeof(mark));
    for(int i=2;i<=maxn;i++)
    {
        if(!mark[i])prime[++tot]=i;
        for(int j=1;j<=tot&&prime[j]*i<=maxn;j++)
        {
            mark[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
    prime_sum[0] = 0;
    for(int i = 1; i <= tot; i++) prime_sum[i] = prime_sum[i-1] + prime[i];
}

int main()
{
	prime_init();
	int x;
	while(~scanf("%d", &x) && x != 0)
	{
		int l = 0, r = 1, ans = 0;
		while(prime[r] <= x)
		{
			while(prime_sum[r] - prime_sum[l] < x) r++;
			if(prime_sum[r] - prime_sum[l] == x) ans++, r++;
			while(prime_sum[r] - prime_sum[l] > x) l++;
			if(prime_sum[r] - prime_sum[l] == x) ans++, l++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
