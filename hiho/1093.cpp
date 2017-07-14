// SPFA
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define maxn 100007
#define maxm 1000007

using namespace std;

int n, m, s, t, edge_idx;
int head[maxn];
struct node
{
    int to, next, w;
}edges[maxm];

void add_edge(int u, int v, int w)
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
}


int dist[maxn];
bool SPFA(int s)
{
    bool visit[maxn];
    int queue[maxn];
    int outque[maxn];
    int iq = 0;
    for (int i = 1; i <= n; ++i)
    {
        dist[i] = 1000000000;
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

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    build_graph();
    cin >> n >> m >> s >> t;
    int a, b, w;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> w;
        add_edge(a, b, w);
        add_edge(b, a, w);
    }
    SPFA(s);
    printf("%d\n", dist[t]);
    return 0;
}