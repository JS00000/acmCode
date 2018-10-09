// Time_Limit_Exceed
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000007
#define maxm 6000007
using namespace std;

int n, m, edge_idx;
int head[maxn];
struct node
{
    int next, to, c;
}edges[maxm];

void add_edge(int u, int v, int c)
{
    edges[edge_idx].c = c;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    edge_idx = 0;
    scanf("%d%d", &n, &m);
    int x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            scanf("%d", &x);
            add_edge(m*(i-1)+j, m*(i-1)+j+1, x);
            add_edge(m*(i-1)+j+1, m*(i-1)+j, x);
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &x);
            add_edge(m*(i-1)+j, m*i+j, x);
            add_edge(m*i+j, m*(i-1)+j, x);
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            scanf("%d",&x);
            add_edge(m*(i-1)+j, m*i+j+1, x);
            add_edge(m*i+j+1, m*(i-1)+j, x);
        }
    }
}

int level[maxn];
bool makelevel(int s, int t)
{
    memset(level, 0, sizeof(level));
    level[s] = 1;
    int que[maxn];
    int iq = 0;
    que[iq++] = s;
    int i, k;
    int top;
    for(i = 0; i < iq; i++)
    {
        top = que[i];
        if (top == t) return true;
        for(k = head[top]; k != -1; k = edges[k].next)
        {
            if (!level[edges[k].to] && edges[k].c)
            {
                que[iq++] = edges[k].to;
                level[edges[k].to] = level[top] + 1;
            }
        }
    }
    return false;
}

int DFS(int now, int maxf, int t)
{
    if (now == t) return maxf;
    int ret = 0, c;
    int k;
    for (k = head[now]; k != -1; k = edges[k].next)
    {
        if (edges[k].c && level[edges[k].to] == level[now] + 1)
        {
            c = DFS(edges[k].to, min(maxf-ret, edges[k].c), t);
            edges[k].c -= c;
            edges[k^1].c += c;
            ret += c;
            if (ret == maxf) return ret;
        }
    }
    return ret;
}
int DINIC(int s, int t)
{
    int ans = 0;
    while(makelevel(s, t)) ans += DFS(s, ~0u>>1, t);
    return ans;
}
int main()
{
    build_graph();
    printf("%d\n", DINIC(1, n*m));
    return 0;
}
