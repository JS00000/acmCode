#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

set<pair<int, int> > s;

int main()
{
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        s.insert(make_pair(x, y));
    }
    int x1, y1, x2, y2;
    long long ans = 0x7fffffff, t;
    for (std::set<pair<int, int> >::iterator i = s.begin(); i != s.end(); ++i) {
        x1 = i->first;
        y1 = i->second;
        for (std::set<pair<int, int> >::iterator j = s.begin(); j != s.end(); ++j) {
            if (i != j) {
                x2 = j->first;
                y2 = j->second;
                if (x1 != x2 && y1 != y2 && s.count(make_pair(x1, y2)) && s.count(make_pair(x2, y1))) {
                    t = abs((long long)(x2 - x1) * (y2 - y1));
                    if (t < ans) {
                        ans = t;
                    }
                }
            }
        }
    }
    if (ans == 0x7fffffff) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}
