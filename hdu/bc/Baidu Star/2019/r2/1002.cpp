#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool a[50][50];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M;
		char in[60], out[60];
		scanf("%d%d", &N, &M);
		memset(a, 0, sizeof(a));
		for (int k = 0; k < N; k++) {
			scanf("%s%s", in, out);
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < M; j++) {
					if (in[i] != out[j]) {
						a[i][j] = 1;
					}
				}
			}
		}
		int ret[50];
		bool flag = 0;
		for (int i = 0; i < M; i++) {
			int j = 0;
			for (j = 0; j < M; j++) {
				if (a[i][j] == 0) {
					ret[i] = j;
					for (int k = i+1; k < M; k++) {
						a[k][j] = 1;
					}
					break;
				}
			}
			if (j == M) flag = 1;
		}
		if (flag) {
			printf("-1\n");
		} else {
			for (int i = 0; i < M-1; i++) {
				printf("%d ", ret[i]+1);
			}
			printf("%d\n", ret[M-1]+1);
		}
	}
	return 0;
}
