#include <queue>
#include <cstdio>
#include <algorithm>
#define maxn 1007
using namespace std;

struct node
{
    double dist;
    int sn;
    node(double d, int s) {
        dist = d;
        sn = s;
    }
    bool operator < (node a) const {
        return dist / sn < a.dist / sn;
    }
};
priority_queue<node> q;


int main()
{
    int n, m, k, d, ld;
    scanf("%d%d%d", &n, &m, &k);
    scanf("%d", &ld);
    for (int i = 1; i < n; i++) {
        scanf("%d", &d);
        q.push(node(d-ld, 1));
        ld = d;
    }
    while (k--) {
        node t = q.top();
        q.pop();
        q.push(node(t.dist * t.sn / (t.sn + 1), t.sn + 1));
    }
    printf("%.1f\n", q.top().dist);
    return 0;
}
