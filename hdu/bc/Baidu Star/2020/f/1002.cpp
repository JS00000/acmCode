#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 100010
using namespace std;

char S[maxn], T[maxn];
int d[maxn], t1[maxn];

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        scanf("%s%s", S+1, T+1);
        S[n+1] = T[n+1] = '0';
        d[0] = t1[0] = 0;
        int ans = 0;
        for(int i = 1; i <= n + 1; i++) {
            d[i] = d[i-1];
            t1[i] = t1[i-1];
            if(T[i] == '1') {
                t1[i]++;
            }
            if(S[i] != T[i]) {
                ans++;
                d[i]++;
            }
        }
        int s0 = 0;
        for(int i = 1; i <= n + 1; i++) {
            if(S[i] == '0') {
                s0++;
                ans = min(ans, s0 + t1[i-1] + d[n+1] - d[i] + (T[i] == '0'? 1 : 0));
            } else {
                ans = min(ans, s0 + 2 + t1[i-1] + d[n+1] - d[i] + (T[i] == '0'? 1 : 0));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
