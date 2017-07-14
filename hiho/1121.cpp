#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 10007
#define maxm 100007
using namespace std;

int n, m, edge_idx;
int head[maxn];
bool color[maxn];
bool visit[maxn];
struct node
{
    int to, next;
}edges[maxm*10];

void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    memset(visit, 0, sizeof(visit));
    memset(color, 0, sizeof(color));
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

bool bfs(int u)
{
    int q[maxn], iq = 0, i = 0;
    q[iq++] = u;
    visit[u] = 1;
    color[u] = 1;
    while(i < iq)
    {
        for (int k = head[q[i]]; k != -1; k = edges[k].next)
        {
            int v = edges[k].to;
            if (visit[v])
            {
                if (color[v] == color[q[i]]) return false;
            }
            else
            {
                visit[v] = 1;
                color[v] = !color[q[i]];
                q[iq++] = v;
            }
        }
        i++;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        build_graph();
        bool flag = 1;
        for (int i = 1; i <= n; i++)
            if (!visit[i]) flag &= bfs(i);
        printf("%s\n", flag? "Correct" : "Wrong" );
    }
    return 0;
}
