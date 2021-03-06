// 费用流
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 6000
#define maxm 100007
using namespace std;

int n, m, edge_idx;
int head[maxn];
struct node
{
    int to, next, c, w;
}edges[maxm*10];

void add_edge(int u, int v, int c, int w)
{
    edges[edge_idx].c = c;
    edges[edge_idx].w = w;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    edge_idx = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add_edge(0,i,b,a);
        add_edge(i,0,0,-a);
        add_edge(i,n+1,d,-c);
        add_edge(n+1,i,0,c);
    }
    for (int i = 1; i <= m; i++) {
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        add_edge(u,v,~0u>>1,k);
        add_edge(v,u,0,-k);
        add_edge(v,u,~0u>>1,k);
        add_edge(u,v,0,-k);
    }
}


int dis[maxn], load[maxm], pre[maxn];
bool flag[maxn];
// dis:距离数组, load:前驱边, pre:前驱点
// flag:点是否入队
bool spfa(int start, int end, int N)
{
    int que[maxn*10], qout, qin;
    memset(flag, 0, sizeof(flag));
    memset(load, -1, sizeof(load));
    memset(pre, -1, sizeof(pre));
    for (int i = 0; i <= N; i++) dis[i] = ~0u>>1;
    qin = qout = 0;
    que[qin++] = start;
    dis[start] = 0;
    flag[start] = 1;
    while(qin != qout)
    {
        int e = que[qout++];
        flag[e] = false;
        for (int k = head[e]; k != -1; k = edges[k].next)
        {
            if (edges[k].c)
            {
                int ne = edges[k].to;
                if (dis[ne] - dis[e] > edges[k].w)
                {
                    dis[ne] = dis[e] + edges[k].w;
                    pre[ne] = e;
                    load[ne] = k;
                    if (!flag[ne])
                    {
                        flag[ne] = 1;
                        que[qin++] = ne;
                    }
                }
            }
        }
    }
    if (dis[end] == ~0u>>1) return 0;
    return 1;
}

int min_cost_flow(int start, int end, int N)
{
    int u, mini, ans_flow = 0, ans_cost = 0;
    while(spfa(start, end, N))
    {
        u = end;
        mini = ~0u>>1;
        while(pre[u] != -1)
        {
            mini = min(mini, edges[load[u]].c);
            u = pre[u];
        }
        u = end;
        while(pre[u] != -1)
        {
            edges[load[u]].c -= mini;
            edges[load[u]^1].c += mini;
            u = pre[u];
        }
        ans_cost += dis[end]*mini;
        ans_flow += mini;
    }
    return ans_cost;
}

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        build_graph();
        printf("%d\n", -min_cost_flow(0, n+1, n+2));
    }
    return 0;
}
