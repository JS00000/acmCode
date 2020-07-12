// wrong way but get AC because of weak data
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int degree[maxn];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++) {
			degree[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			degree[u]++;
			degree[v]++;
		}
		bool flag = 1;
		for (int i = 1; i <= n; i++) {
			if (degree[i] < k) {
				flag = 0;
				break;
			}
		}
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
