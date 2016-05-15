#include <bits/stdc++.h>

int n, k;

int main()
{
	while (~scanf("%d%d", &n, &k)) {
		while (n != n/2 +k) {
			n = n/2 + k;
		}
		printf("%d\n", n);
	}
	return 0;
}
