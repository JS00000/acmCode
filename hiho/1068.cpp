// ST表
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 1000007;

int n, q;
int w[N];
int ST[N][24];

int pow(int a, int b)
{
	int base = a, ret = 1;
	while(b)
	{
		if (b & 1) ret *= base;
		base *= base;
		b >>= 1;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	// freopen("in.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", w+i);
	scanf("%d", &q);
	for (int i = 0; i < n; ++i)
	{
		ST[i][0] = w[i];
	}
	for (int j = 1; j <= int(log(n)/log(2)); ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i+pow(2, j-1) < n)
				ST[i][j] = std::min(ST[i][j-1], ST[i+pow(2, j-1)][j-1]);
			else 
				ST[i][j] = ST[i][j-1];
		}
	}

	for (int i = 0; i < q; ++i)
	{
		int l, r, t = 1, j = 0;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		while(t*2 < r-l+1)
		{
			t *= 2;
			j++;
		}
		printf("%d\n", std::min(ST[l][j], ST[r-t+1][j]));
	}
	return 0;
}
