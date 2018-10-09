#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 600
#define maxm 100007
using namespace std;

int n, q, edge_idx;
int head[maxn];
struct node
{
    int to, next, c, w;
}edges[maxm];

int mi[51], ma[51];

void add_edge(int u, int v, int c, int w)
{
    edges[edge_idx].c = c;
    edges[edge_idx].w = w;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
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
    scanf("%d%d", &n, &q);
    memset(head, -1, sizeof(head));
    edge_idx = 0;
    for (int i = 1; i <= n; i++) {
        mi[i] = 1;
        ma[i] = n;
    }
    for (int i = 1; i <= q; i++) {
        int t, l, r, v;
        scanf("%d%d%d%d", &t, &l, &r, &v);
        for (int j = l; j <= r; j++)
            if (t == 1) mi[j] = max(mi[j], v);
            else ma[j] = min(ma[j], v);
    }
    for (int i = 1; i <= n; i++) {
        if (mi[i] > ma[i]) {
            printf("-1\n");
            return 0;
        }
    }
    // S:0
    // T:2n+1
    // 1~n:1~n
    // s1~sn:n+1~2n
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n*2-1; j+=2) {
            add_edge(0, i, 1, j);
            add_edge(i, 0, 0, -j);
        }
        for (int j = mi[i]; j <= ma[i]; j++) {
            add_edge(j, n+i, 1, 0);
            add_edge(n+i, j, 0, 0);
        }
        add_edge(n+i, 2*n+1, 1, 0);
        add_edge(2*n+1, n+i, 0, 0);
    }
    printf("%d\n", min_cost_flow(0, 2*n+1, 2*n+2));
    return 0;
}
