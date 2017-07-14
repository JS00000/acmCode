#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
#define maxm 10007
using namespace std;

int n, m, edge_idx;
int head[maxn];
int match[maxn];
bool visit[maxn];
bool matched[maxn];
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
    memset(head, -1, sizeof(head));
    memset(matched, 0, sizeof(matched));
    edge_idx = 0;
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }
}

bool find_path(int u)
{
    if (visit[u]) return false;
    visit[u] = 1;
    for (int k = head[u]; k != -1; k = edges[k].next)
    {
        int v = edges[k].to;
        if (!matched[v] || find_path(match[v]))
        {
            match[u] = v;
            match[v] = u;
            matched[u] = matched[v] = 1;
            return true;
        }
    }
    return false;
}

int main()
{
    int ans = 0;
    build_graph();
    for (int i = 1; i <= n; ++i)
    {
        if (!matched[i])
        {
            memset(visit, 0, (n+1)*sizeof(bool));
            ans += find_path(i);
        }
    }
    printf("%d\n", ans);
    printf("%d\n", n-ans);
    return 0;
}
