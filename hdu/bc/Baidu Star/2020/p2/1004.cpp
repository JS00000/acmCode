#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

int cnt[10];
int d[1024][10];

int dfs(int s, int n) {
    if(d[s][n] != -1) 
        return d[s][n];
    d[s][n] = 0;
    for(int i = (s-1) & s; i; i = (i-1) & s) {
        d[s][n] = max(d[s][n], min(dfs(i, n-1), d[s-i][1]));
    }
    return d[s][n];
}

int main()
{
    int t; 
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++) {
            int num; scanf("%d", &num);
            cnt[num%10]++;
        }
        for(int i = 0; i < 1024; i++) {
            for(int j = 0; j < 10; j++) {
                d[i][j] = -1;
            }
        }
        for(int i = 0; i < 1024; i++) {
            d[i][1] = 0;
            for(int j = 0; j < 10; j++) {
                if(i & (1<<j)) {
                    d[i][1] += cnt[j];
                }
            }
        }
        printf("%d\n", n - dfs(1023, 5));
    }
    return 0;
}