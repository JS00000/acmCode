// 水题
#include <cstdio>
using namespace std;
int n, it, L, odd, ans;
int main()
{
	scanf("%d", &n);
	ans = n, L = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &it);
		if (L == 0)
		{
			odd = (it & 1);
			L = 1;
			continue;
		}
		if ((it ^ odd) & 1) ans -= 2, L--;
		else L++;
	}
	printf("%d\n", ans);
}
