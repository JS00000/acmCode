#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 5;

int color[maxn * 2];

int main()
{
	int n, minc = 1e9;
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i++)
	{
		scanf("%d", &color[i]);
		minc = min(minc, color[i + n] = color[i]);
	}
	
	int sum = 0, maxc = 0;
	for (int i = 0 ; i < 2 * n ; i++)
	{
		if (color[i] - minc > 0)
			sum++;
		else
		{
			maxc=max(maxc,sum);
			sum=0;
		}
	}
	printf("%I64d",(long long)minc*n+maxc);
	return 0;
}