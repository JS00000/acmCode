#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 10007;

int n, q;
int w[N];


int main(int argc, char const *argv[])
{
	// freopen("in.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", w+i);
	scanf("%d", &q);
	int p, a, b, minx;
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%d%d", &p, &a, &b);
		if (p == 0)
		{
			minx = w[a-1];
			for (int j = a; j < b; ++j)
			{
				if (minx > w[j])
				{
					minx = w[j];
				}
			}
			printf("%d\n", minx);
		}
		else
		{
			w[a-1] = b;
		}
	}
	return 0;
}