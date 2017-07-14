// 枚举
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 16
int flip[maxn] = {19, 39, 78, 140, 305, 626, 1252, 2248, 4880, 10016, 20032, 35968, 12544, 29184, 58368, 51200};
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
	bool p = x & 1;
	x >>= 1;
	for (int i = 1; i < 16; i++, x >>= 1)
		if (p != (x&1)) return 0;
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
			if (instr[j] == 'b') mp += qpow(2, j+i*4);
	}
	for (int k = 0; k <= 16; k++)
		dfs(a, maxn, k, 0, -1, mp);
	printf("Impossible\n");
	return 0;
}
