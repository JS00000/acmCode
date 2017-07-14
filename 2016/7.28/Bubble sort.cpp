#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	int t, n;
	int a[100007];
	int d[100007];
	int pos[100007];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", a+i);
			pos[a[i]] = i;
		}
		memset(d, 0, n*sizeof(int));
		d[n-1] = 0;
		for (int i = n-2; i >= 0; --i)
		{
			int j = i+1;
			while(j < n)
			{
				d[i]++;
				if (a[j] < a[i])
				{
					d[i] += d[j];
					break;
				}
				j++;
			}
			if (j == n) d[i] = 0;
		}
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", d[i]);
		}
	}
	return 0;
}