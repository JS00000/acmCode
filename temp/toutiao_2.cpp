#include <cstdio>
#include <algorithm>
#define maxn 500007
using namespace std;

struct node
{
    int x, y;
}point[maxn], ans[maxn];

bool cmp(node a, node b)
{
    return a.x == b.x ? a.y > b.y : a.x > b.x;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &point[i].x, &point[i].y);
    }
    sort(point, point+n, cmp);
    int maxy = -1, ans_idx = 0;
    for (int i = 0; i < n; i++) {
        if (point[i].y > maxy) {
            maxy = point[i].y;
            ans[ans_idx++] = point[i];
        }
    }
    for (int i = ans_idx - 1; i >= 0; i--) {
        printf("%d %d\n", ans[i].x, ans[i].y);
    }
    return 0;
}
