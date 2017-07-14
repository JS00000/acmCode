#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000007
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

int main()
{
	prime_init();
	mark[0] = mark[1] = 1;
	int a, d, n, k;
	while(~scanf("%d%d%d", &a, &d, &n) && !(a == 0 && d == 0 && n == 0))
	{
		k = 0;
		while(n)
		{
			if (!mark[a+k*d]) n--;
			k++;
		}
		printf("%d\n", a+(k-1)*d);
	}
	return 0;
}
