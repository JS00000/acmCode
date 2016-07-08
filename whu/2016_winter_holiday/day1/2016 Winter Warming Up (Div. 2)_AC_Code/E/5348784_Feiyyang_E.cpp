#include<stdio.h>  
#include<string.h>  
#include<math.h>  
#include<queue>  
#include<stack>  
#include<iostream>  
#include<algorithm>  
#define INF 0x7fffffff  
#define MAXN 200010  
#define mem(x) memset(x,0,sizeof(x))  
#define eps 1e-8  
#define LL __int64  
using namespace std;
LL a[MAXN];
int main()
{
	int t, i;
	int n, bz;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
			scanf("%I64d", &a[i]);
		LL mi = INF;//这里定义成int，然后死活过不了  
		int k;
		for (i = n; i >= 1; i--)
		{
			if (a[i]<mi)
			{
				mi = a[i];
			}
		}
		for (i = 1; i <= n; i++)
			a[i] -= mi;
		i = 1;
		int len = 0;
		int M = 0;
		while (i <= n)
		{
			if (a[i])
				len++;
			else
			{
				M = max(M, len);
				len = 0;
			}
			i++;
		}
		if (a[n])
		{
			//printf("len=%d\n",len);  
			i = 1;
			while (a[i])
			{
				len++;
				i++;
			}
			//printf("len=%d\n",len);  
			M = max(M, len);
		}
		LL ans = mi*n + M;
		printf("%I64d\n", ans);
	}
	return 0;
}