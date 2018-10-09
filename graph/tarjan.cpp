#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
#define maxm 50100
using namespace std;

int n, m, edge_idx;
int head[maxn];
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
    edge_idx = 0;
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
}

int is, scc_num;
int temp[maxn], low[maxn], dfn[maxn], stack[maxn];

int tar_bfs(int x, int lay)
{
    temp[x] = 1;
    low[x] = lay;
    dfn[x] = lay;
    stack[++is] = x;
    for (int k = head[x]; k != -1; k = edges[k].next) {
        if (temp[edges[k].to] == 0) {
            tar_bfs(edges[k].to, ++lay);
        }
        if (temp[edges[k].to] == 1) {
            low[x] = min(low[x], low[edges[k].to]);
        }
    }
    if (dfn[x] == low[x]) {
        ++scc_num;
        do {
            low[stack[is]] = scc_num;
            temp[stack[is]] = 2;
        } while (stack[is--] != x);
    }
    return 0;
}

int tarjan()
{
    scc_num = 0;
    is = 0;
    memset(temp, 0, sizeof(temp));
    memset(low, 0, sizeof(low));
    for (int i = 1; i <= n; i++) {
        if (temp[i] == 0) tar_bfs(i, 1);
    }
    return scc_num;
}

int main()
{
    freopen("con.in", "r", stdin);
    build_graph();
    printf("%d\n", tarjan());
    for (int i = 1; i <= n; ++i)
        printf("%d ", low[i]);
    printf("\n");
    return 0;
}
