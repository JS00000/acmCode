#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, ans = 0, rp = 0, rt = 0, a, b;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			if (rp > 0) {
				int t = min(rp, b);
				ans += t;
				rp -= t;
				b -= t;
			}
			if (rt > 0) {
				int t = min(rt, a);
				ans += t;
				rt -= t;
				a -= t;
			}
			rt += b;
			rp += a;
		}
		if (rt > 0 && rp > 0) {
			// int t = min(min(rp, rt), ans);
			// ans += t;
			if (ans > rt) {
				ans += min(rp, rt);
			} else {
				ans += min(rp, ans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
