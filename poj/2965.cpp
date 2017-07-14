// 枚举
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 16
int flip[maxn] = {4383, 8751, 17487, 34959, 4593, 8946, 17652, 35064, 7953, 12066, 20292, 36744, 61713, 61986, 62532, 63624};
int a[maxn];

void show(int x)
{
	for (int i = 0; i < maxn; i++)
	{
		printf("%d", x&1);
		x >>= 1;
	}
	printf("\n");
}

bool check(int x)
{
	for (int i = 0; i < 16; i++, x >>= 1) if (x&1) return 0;
	return 1;
}

void dfs(int a[], int n, int m, int d, int last, int mp)
{
	if (d < m) for (a[d] = last+1; a[d] < n; a[d]++) dfs(a, n, m, d+1, a[d], mp);
	else
	{
		for (int i = 0; i < d; i++) mp ^= flip[a[i]];
		if (check(mp))
		{
			printf("%d\n", m);
			for (int i = 0; i < d; i++) printf("%d %d\n", a[i]/4+1, a[i]%4+1);
			exit(0);
		}
	}
}

long long qpow(long long a,long long b)
{
    long long ans=1;
    for(int i=b;i;i>>=1,a=a*a)
        if(i&1)ans=ans*a;
    return ans;
}

int main()
{
	char instr[4];
	int mp = 0;
	for (int i = 0; i < 4; i++)
	{
		scanf("%s", instr);
		for (int j = 0; j < 4; j++)
			if (instr[j] == '+') mp += qpow(2, j+i*4);
	}
	for (int k = 0; k <= 16; k++)
		dfs(a, maxn, k, 0, -1, mp);
	printf("Impossible\n");
	return 0;
}
