#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

int n, m, edge_idx;
int head[maxn], deg_in[maxn];
struct node
{
    int to, next;
}edges[maxn*2];

inline void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    memset(deg_in, 0, sizeof(deg_in));
    edge_idx = 0;
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        deg_in[v]++;
    }
}

int q[maxn];
void solve()
{
    int i = 0, iq = 0;
    for (int j = 1; j <= n; j++)
        if (deg_in[j] == 0)
            q[iq++] = j;
    while (i < iq) {
        for (int k = head[q[i]]; k != -1; k = edges[k].next)
            if (!--deg_in[edges[k].to])
                q[iq++] = edges[k].to;
        i++;
    }
    if (iq < n)
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        build_graph();
        solve();
    }
    return 0;
}
