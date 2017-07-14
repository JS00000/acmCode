#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

int n, m;
struct node
{
    int time;
    int type;
}nodes[maxn*4];

bool cmp(node n1, node n2)
{
    return n1.time == n2.time ? n1.type < n2.type : n1.time < n2.time;
}

int main()
{
    scanf("%d%d", &n, &m);
    int be, en;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &be, &en);
        nodes[i*2].time = be;
        nodes[i*2].type = 2;
        nodes[i*2+1].time = en;
        nodes[i*2+1].type = -2;
    }
    for (int i = n; i < n + m; i++)
    {
        scanf("%d%d", &be, &en);
        nodes[i*2].time = be;
        nodes[i*2].type = 1;
        nodes[i*2+1].time = en;
        nodes[i*2+1].type = -1;
    }
    sort(nodes, nodes+n*2+m*2, cmp);
    int ta = 0, tb = 0, ans = 0;
    if (nodes[0].type == -2 || nodes[0].type == 2) ta += nodes[0].type;
    if (nodes[0].type == -1 || nodes[0].type == 1) tb += nodes[0].type;
    for (int i = 1; i < n*2 + m*2; i++)
    {
        if (ta > 0 && tb == 0) ans += nodes[i].time - nodes[i-1].time;
        if (nodes[i].type == -2 || nodes[i].type == 2) ta += nodes[i].type;
        if (nodes[i].type == -1 || nodes[i].type == 1) tb += nodes[i].type;
    }
    printf("%d\n", ans);
    return 0;
}
