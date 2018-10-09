// 最长回文子串
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1 << 23;
int f[N];
char s[N],str[N];

int main()
{
    // freopen("h_1.in", "r", stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s",s);
        str[0] = '$';
        str[1] = '#';
        int n = 2;
        for(int i = 0; s[i]; i ++) {
            str[n ++] = s[i];
            str[n ++] = '#';
        }
        int ma = 0, j;
        for(int i = 1; i < n; i ++) {
            if(ma > i) f[i] = min(ma - i,f[2 * j - i]);
            else f[i] = 1;
            while(str[i - f[i]] == str[i + f[i]]) f[i]++;
            if(f[i] + i > ma) {
                ma = f[i] + i;
                j = i;
            }
        }
        int ans = 0;
        for(int i = 1;i < n;i ++)
            ans = max(ans, f[i] - 1);
        printf("%d\n",ans);
    }
}
