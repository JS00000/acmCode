#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;



int main()
{
	int n, m, c1 = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) c1++;
	}
	if (c1 >= 2) printf("2\n");
	else printf("3\n");
	return 0;
}
