#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 507;
const int maxm = 42007;

int n, m, edge_idx;
int head[maxn];
struct node
{
    int c, next, to;
}edges[maxm];

void add_edge(int u, int v, int c)
{
    edges[edge_idx].c = c;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

int sap_max_flow(int start, int end, int N)
{
    int numh[maxn], h[maxn], curedge[maxn], pre[maxn];
    // numh:用于GAP优化的统计高度数量数组; h:距离标号数组; curedge:当前弧数组; pre:前驱数组
    int cur_flow, flow_ans = 0, u, tmp, neck, i;
    memset(h, 0, sizeof(h));
    memset(numh, 0, sizeof(numh));
    memset(pre, -1, sizeof(pre));
    for (i = 1; i <= N; ++i)
        curedge[i] = head[i];
    numh[0] = N;
    u = start;
    while(h[start] < N)
    {
        if (u == end)
        {
            cur_flow = ~0u>>1;
            for (i = start; i != end; i = edges[curedge[i]].to)
            {
                if (cur_flow > edges[curedge[i]].c)
                {
                    neck = i;
                    cur_flow = edges[curedge[i]].c;
                }
            }
            for (i = start; i != end; i = edges[curedge[i]].to)
            {
                tmp = curedge[i];
                edges[tmp].c -= cur_flow;
                edges[tmp^1].c += cur_flow;
            }
            flow_ans += cur_flow;
            u = neck;
        }
        for (i = curedge[u]; i != -1; i = edges[i].next)
            if (edges[i].c && h[u]==h[edges[i].to]+1) break;
        if (i != -1)
        {
            curedge[u] = i;
            pre[edges[i].to] = u;
            u = edges[i].to;
        }
        else
        {
            if (0 == --numh[h[u]]) break; //GAP优化
            curedge[u] = head[u];
            for (tmp = N, i = head[u]; i != -1; i = edges[i].next)
                if (edges[i].c) tmp = min(tmp, h[edges[i].to]);
            h[u] = tmp + 1;
            ++numh[h[u]];
            if (u != start) u = pre[u];
        }
    }
    return flow_ans;
}


int main()
{
    while (~scanf("%d%d", &n, &m)) {
        int sum = 0;
        memset(head, -1, sizeof(head));
        int temp;
        edge_idx = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &temp);
            sum += temp;
            add_edge(1, 2+i, temp);
            add_edge(2+i, 1, 0);
            add_edge(2+n+i, 2, temp);
            add_edge(2, 2+n+i, 0);       
        }
        for (int i = 1; i <= m; ++i)
        {
            int ia, ib;
            scanf("%d%d", &ia, &ib);
            add_edge(2+ia, 2+n+ib, 1);
            add_edge(2+n+ib, 2+ia, 0);
            add_edge(2+ib, 2+n+ia, 1);
            add_edge(2+n+ia, 2+ib, 0);
        }
        int flow = sap_max_flow(1, 2, n*2+2);
        if (flow == sum) puts("Yes");
        else puts("No");
    }
    return 0;
}
