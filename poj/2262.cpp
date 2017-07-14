#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000000
using namespace std;

int tot = 0;
int prime[maxn+7];
bool mark[maxn+7];
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
}

void solve(int n)
{
	for (int i = 1; prime[i] < n; i++)
		if (!mark[n - prime[i]])
		{
			printf("%d = %d + %d\n", n, prime[i], n - prime[i] );
			return;
		}
}

int main()
{
	prime_init();
	int n;
	while(~scanf("%d", &n) && n != 0) solve(n);
	return 0;
}
