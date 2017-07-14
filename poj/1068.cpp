#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100
using namespace std;

int a[maxn];
int d[maxn];
int c[maxn];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a+i);
		d[0] = a[0];
		for (int i = 1; i < n; ++i) d[i] = a[i] - a[i-1];
		for (int i = 0; i < n; ++i) c[i] = 0;
		for (int i = 0; i < n; ++i)
		{
			int j = i, ans = 0;
			while(!d[j]) ans += c[j], j--;
			d[j]--, ans += c[j]++;
			printf("%d ", ans+1);
		}
		printf("\n");
	}
	return 0;
}
