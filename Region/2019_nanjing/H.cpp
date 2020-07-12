#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
#define maxm 2007
using namespace std;

int n, m, edge_idx;
int head[maxn];
struct node
{
    int to, next;
    long long w;
}edges[maxm*2];

inline void add_edge(int u, int v, int w)
{
    edges[edge_idx].w = w;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    edge_idx = 0;
    scanf("%d%d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }
}

long long inf = 0x3f3f3f3f3f3f3f3f;
long long dist[maxn];
bool SPFA(int s)
{
    bool visit[maxn];
    int queue[maxn];
    int outque[maxn];
    int iq = 0;
    for (int i = 0; i <= n; ++i)
    {
        dist[i] = inf;
    }
    memset(visit, 0, sizeof(visit));
    memset(outque, 0, sizeof(outque));
    queue[iq++] = s;
    visit[s] = 1;
    dist[s] = 0;
    int i = 0;
    while(i != iq)
    {
        int top = queue[i];
        visit[top] = 0;
        outque[top]++;
        if (outque[top] > n) return false;
        for (int k = head[top]; k != -1; k = edges[k].next)
        {
            if (dist[edges[k].to] - edges[k].w > dist[top])
            {
                dist[edges[k].to] = dist[top] + edges[k].w;
                // printf("%d ", dist[edges[k].to]);
                if (!visit[edges[k].to])
                {
                    visit[edges[k].to] = 1;
                    queue[iq++] = edges[k].to;
                    if (iq >= n) iq = 0;
                }
            }
        }
        i++;
        if (i >= n) i = 0;
    }
    return true;
}


int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        build_graph();
        for (int i = 0; i < 6; i++) {
            int s, t;
            scanf("%d%d", &s, &t);
            SPFA(t);
            printf("%lld\n", -dist[s]);
            add_edge(s, t, -dist[s]);
        }
    }
    return 0;
}
