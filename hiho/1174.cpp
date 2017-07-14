// topology
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
#define maxm 500007
using namespace std;

int n, m, edge_idx;
int head[maxn], indegree[maxn];
struct node
{
    int to, next;
}edges[maxm*2];

void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
    indegree[v]++;
}

void build_graph()
{
    scanf("%d%d", &n, &m);
    memset(head, -1, (n+1)*sizeof(int));
    memset(indegree, 0, (n+1)*sizeof(int));
    edge_idx = 0;
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &a, &b);
        add_edge(a, b);
    }
}

bool topology()
{
    int iq = 0, q[maxn];
    for (int i = 1; i <= n; ++i)
        if (!indegree[i]) q[iq++] = i;
    for (int i = 0; i < iq; ++i)
        for (int k = head[q[i]]; k != -1; k = edges[k].next)
            if (!--indegree[edges[k].to]) 
                q[iq++] = edges[k].to;
    return iq == n;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        build_graph();
        printf("%s\n", topology() ? "Correct":"Wrong");
    }
    return 0;
}
