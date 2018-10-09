#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

char s[maxn];
map<pair<int, int>, int> mp;

int best(int l, int r) {
    int ret = r-l;
    if (ret == 0) return 0;
    if (mp.count(make_pair(l, r))) return mp[make_pair(l, r)];
    for (int i = l+1; i < r; i++)
        ret = min(ret, best(l, i)+best(i, r));
    for (int k = 2; k <= r-l; k++) {
        if ((r-l) % k == 0) {
            bool flag = 1;
            for (int i = 0; i < (r-l)/k; i++) {
                if (!flag) break;
                for (int j = 1; j < k; j++) {
                    if (s[l + i + (j-1)*(r-l)/k] != s[l + i + j*(r-l)/k]) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag) {
                int nk = 0, temp = k;
                while (temp) {
                    temp /= 10;
                    nk++;
                }
                ret = min(ret, nk+2+best(l, l+(r-l)/k));
            }
        }
    }
    mp[make_pair(l, r)] = ret;
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        mp.clear();
        scanf("%s", s);
        printf("%d\n", best(0, strlen(s)));
    }
    return 0;
}
