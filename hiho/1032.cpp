// 最长回文子串
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1 << 23;
int rad[N];
char s[N],str[N];

int main()
{
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
            if(ma > i) rad[i] = min(ma - i,rad[2 * j - i]);
            else rad[i] = 1;
            while(str[i - rad[i]] == str[i + rad[i]]) rad[i] ++;
            if(rad[i] + i > ma) {
                ma = rad[i] + i;
                j = i;
            }
        }
        int ans = 0;
        for(int i = 1;i < n;i ++)
            ans = max(ans, rad[i] - 1);
        printf("%d\n",ans);
    }
}
