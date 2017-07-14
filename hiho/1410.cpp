#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main()
{
	unsigned int a;
	scanf("%u", &a);
	int l = 0, ans = 0;
	while(a)
	{
		if (a & 1) l++;
		else if (l > 1) ans += 1, l = 1;
		else ans += l, l = 0;
		a>>=1;
	}
	if (l > 1) ans += 2;
	else ans += l;
	printf("%d\n", ans);
	return 0;
}
