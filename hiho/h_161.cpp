#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 507
#define maxm 100007
using namespace std;

int n, m, edge_idx;
int head[maxn], fa[maxn];
bool visit[maxn];
struct node
{
    int to, next;
}edges[maxm*2];

void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(fa, -1, sizeof(fa));
    memset(head, -1, sizeof(head));
    memset(visit, 0, sizeof(visit));
    edge_idx = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
}

bool is_tree()
{
    int q[maxn], i = 0, iq = 0;
    q[iq++] = 1;
    visit[1] = 1;
    while (i < iq) {
        int u = q[i++];
        for (int k = head[u]; k != -1; k = edges[k].next) {
            if (!visit[edges[k].to]) {
                visit[edges[k].to] = 1;
                q[iq++] = edges[k].to;
                fa[edges[k].to] = u;
            } else if (fa[u] != edges[k].to) {
                return 0;
            }
        }
    }
    return (iq == n);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        build_graph();
        printf("%s\n", is_tree()?"YES":"NO");
    }
    return 0;
}
