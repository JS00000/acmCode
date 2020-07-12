#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

int a[maxn];



int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, w, ab400 = 0, m = 0;
		scanf("%d", &n);
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &w);
			if (w % 10 != 0) flag = 1;
			w /= 10;
			if (w >= 40) {
				a[m++] = w - w / 10 * 10;
				ab400 = max(ab400, (w - 40) / 10);
			} else {
				a[m++] = w;
			}
		}
		if (flag) {
			printf("-1\n");
			continue;
		}

		int c10 = 0, c20 = 0, c50 = 0, c100 = 0;
		for (int i = 0; i < m; i++) {

		}

	}
	return 0;
}
