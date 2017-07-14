#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

int n;
struct node
{
    int time;
    int add;
}nodes[maxn*2];

bool cmp(node n1, node n2)
{
    return n1.time == n2.time ? n1.add < n2.add : n1.time < n2.time;
}

int main()
{
    scanf("%d", &n);
    int be, en;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &be, &en);
        nodes[i*2].time = be;
        nodes[i*2].add = 1;
        nodes[i*2+1].time = en;
        nodes[i*2+1].add = -1;
    }
    sort(nodes, nodes+n*2, cmp);
    int ma = 0, t = 0;
    for (int i = 0; i < n*2; i++)
    {
        t += nodes[i].add;
        if (t > ma) ma = t;
    }
    printf("%d\n", ma);
    return 0;
}
