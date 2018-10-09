#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int l[maxn], r[maxn];
char s[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int len = strlen(s);
        int mini = len;
        l[0] = 0;
        r[len + 1] = 0;
        for (int i = 1; i <= len; i++) l[i] = l[i-1] + (s[i-1] == '1');
        for (int i = len; i >= 1; i--) r[i] = r[i+1] + (s[i-1] == '0');
        for (int i = 1; i <= len; i++) mini = min(mini, l[i - 1] + r[i + 1]);
        printf("%d\n", mini);
    }
    return 0;
}
