#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

int f[26], last[26];
char s[maxn];

int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        f[s[i] - 'a'] = max(f[s[i] - 'a'], i - last[s[i] - 'a']);
        last[s[i] - 'a'] = i;
    }
    int ans = maxn;
    for (int i = 0; i < 26; i++) {
        f[i] = max(f[i], n + 1 - last[i]);
        if (f[i] != 0) ans = min(ans, f[i]);
    }
    printf("%d\n", ans);
    return 0;
}
