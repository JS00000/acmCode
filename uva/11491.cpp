#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

char b[maxn], str[maxn];

int main()
{
	int n, d;
	while(~scanf("%d%d", &n, &d) && !(n == 0 && d == 0))
	{
		memset(b, 0, sizeof(b));
		scanf("%s", str);
		b[0] = 'a';
		int i = 0, j = 0, k = d;
		while (k)
		{
			while(str[i] > b[j] && j && k) j--, k--;
			b[++j] = str[i++];
			if (i == n) break;
		}
		for (k = j + 1; k <= n-d; k++) b[k] = str[i++];
		b[n-d+1] = '\0';
		printf("%s\n", b+1);
	}
	return 0;
}
