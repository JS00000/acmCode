#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char mp[510][510];
int a[510][510];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", mp[i]);
    }
    for (int i = 0; i < n; i++) {
        int l = 0;
        for (int j = 0; j < n; j++) {
            if (mp[i][j] == '1') {
                l++;
                if (l > 2 && (j == n-1 || (j < n-1 && mp[i][j+1] == '0'))) {
                    for (int k = j-l+2; k < j; k++) {
                        a[i][k] = min(k-(j-l+1), j-k);
                    }
                }
            } else {
                l = 0;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < n; j++) {
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (mp[i][j] == '1') {
                l++;
                if (l > 2 && (i == n-1 || (i < n-1 && mp[i+1][j] == '0'))) {
                    for (int k = i-l+2; k < i; k++) {
                        ans = max(ans, min(a[k][j], min(k-(i-l+1), i-k)));
                    }
                }
            } else {
                l = 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
