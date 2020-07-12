#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

std::priority_queue<int> pq;

int main()
{
	int T;
	scanf("%d", &T);
	getchar();
	while (T--) {
		int seg = 1, n = 1;
		while (1) {
			n++;
			char c = getchar();
			if (c == '?') seg++;
			else if (c == '^') {
				pq.push(seg);
				seg = 1;
			} else {
				pq.push(seg);
				break;
			}
		}
		int ret = 0;
		while (!pq.empty()) {
			int v = pq.top();
			pq.pop();
			if (v == 1) {
				ret ^= 1;
			} else {
				int u = v;
				int t = 0;
				while (u = u >> 1) t++;
				int ma = (1 << t);
				if ((ret & ma) == 0) {
					ret ^= ma;
					if (v > ma) pq.push(v - ma);
				} else {
					pq.push(ma >> 1);
					pq.push(ma >> 1);
					if (v > ma) pq.push(v - ma);
				}
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
