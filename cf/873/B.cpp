#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

int n, diff = 0, ans = 0;
int first[maxn*2];
char s[maxn];

int main()
{
    scanf("%d", &n);
    scanf("%s", s+1);
    memset(first, -1, sizeof(first));
    first[n] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') diff++;
        else diff--;
        if (first[diff + n] != -1) ans = max(ans, i - first[diff + n]);
        else first[diff + n] = i;
    }
    printf("%d\n", ans);
    return 0;
}
