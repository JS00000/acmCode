// hdu 6055
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 507
using namespace std;

struct point {
    int x, y;
} node[maxn];

set<pair<int, int> > s;

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        s.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &node[i].x, &node[i].y);
            s.insert(make_pair(node[i].x, node[i].y));
        }
        int sum = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int x1 = node[i].x + node[j].x + node[i].y - node[j].y;
                int y1 = node[i].y + node[j].y - node[i].x + node[j].x;
                int x2 = node[i].x + node[j].x - node[i].y + node[j].y;
                int y2 = node[i].y + node[j].y + node[i].x - node[j].x;
                if (!(x1 & 1 || x2 & 1 || y1 & 1 || y2 & 1))
                    if (s.count(make_pair(x1/2, y1/2)) && s.count(make_pair(x2/2, y2/2)))
                        sum++;
            }
        }
        printf("%d\n", sum/2);
    }
    return 0;
}
