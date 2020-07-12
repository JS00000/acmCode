#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 10007
using namespace std;

double p[maxn], s[maxn], t[maxn];

bool cmp(double a, double b) {
	return a > b;
}

int main()
{
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf", p+i);
		}
		sort(p, p+n, cmp);
		double ans = p[0];
		s[0] = 1 - p[0];
		t[0] = p[0] / (1 - p[0]);
		for (int i = 1; i < n; i++) {
			s[i] = s[i-1] * (1 - p[i]);
			t[i] = t[i-1] + p[i] / (1 - p[i]);
			ans = max(ans, s[i] * t[i]);
		}
		printf("%.8f\n", ans);
	}
}
