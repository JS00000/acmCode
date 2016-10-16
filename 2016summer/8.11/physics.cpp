#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int c, n, k, t, q, temp;
int v[100007];

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n, &c);
		for (int i = 0; i < n; ++i)
			scanf("%d %d %d", v+i, &temp, &temp);
		sort(v, v+n);
		scanf("%d", &q);
		for (int i = 0; i < q; ++i)
		{
			scanf("%d %d", &t, &k);
			printf("%.3f\n", sqrt( double(v[k-1])*v[k-1] + 2.*c*t) );
		}
	}
	return 0;
}
