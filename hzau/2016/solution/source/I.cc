#include <bits/stdc++.h>

const int MAXN = 11;

int v, n;
int p[MAXN];
int d[MAXN];

int main()
{
	while (~scanf("%d%d", &n, &v)) {
		double pos = 0;
		double t = 0;
		bool tag = true;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", p+i, d+i);
			if (tag == false) {
				continue;
			}
			if (d[i] * (p[i] + d[i]*t - pos) > 0) {
				if (v <= std::abs(d[i])) {
					tag = false;
					continue;
				}
				t += std::abs(p[i] + d[i] * t - pos) / (v - std::abs(d[i]));  
				pos = p[i] + d[i] * t;
			}
			else {
				t += std::abs(p[i] + d[i] * t - pos) / (v + std::abs(d[i]));
				pos = p[i] + d[i] * t;
			}
		}
		if (true == tag) {
			printf("%.2f\n", t);
		}
		else {
			printf("Bad Dog\n");
		}
	}
}
