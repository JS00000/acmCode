// Tarjan
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 20007
#define maxm 100007
using namespace std;

int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

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
    n = read(), m = read();
    // scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read();
        // int a, b;
        // scanf("%d%d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }
}

int NIL, parent[maxn], low[maxn], dfn[maxn];

int cut_point[maxn], point_idx, edge2_idx;
struct node2
{
    int a, b;
    node2(){}
    node2(int u, int v): a(u), b(v){}
} cut_edges[maxm];

bool edge_cmp(node2 a, node2 b)
{
    return a.a == b.a ? a.b < b.b: a.a < b.a;
}

bool edge_equ(node2 a, node2 b)
{
    return a.a == b.a && a.b == b.b;
}

void dfs(int u) {
    //记录dfs遍历次序
    static int counter = 0;
    //记录节点u的子树数
    int children = 0;
    //初始化dfn与low
    dfn[u] = low[u] = ++counter;
    for(int k = head[u]; k != -1; k = edges[k].next) {
        int v = edges[k].to;
        //节点v未被访问，则(u,v)为树边
        if(!dfn[v]) {
            children++;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            //case (1)
            if(parent[u] == NIL && children > 1) {
                // printf("articulation point: %d\n", u);
                cut_point[point_idx++] = u;
            }
            //case (2)
            if(parent[u] != NIL && low[v] >= dfn[u]) {
                // printf("articulation point: %d\n", u);
                cut_point[point_idx++] = u;
            }
            //bridge
            if(low[v] > dfn[u]) {
                // printf("bridge: %d %d\n", u, v);
                cut_edges[edge2_idx++] = node2(min(u, v), max(u, v));
            }
        }
        //节点v已访问，则(u,v)为回边
        else if(v != parent[u]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main()
{
    build_graph();
    memset(dfn, 0, sizeof(dfn));
    NIL = parent[1] = -1, point_idx = 0, edge2_idx = 0;
    dfs(1);
    int k;
    if (point_idx == 0) printf("Null\n");
    else
    {
        sort(cut_point, cut_point+point_idx);
        k = unique(cut_point, cut_point+point_idx) - cut_point;
        for (int i = 0; i < k-1; ++i)
            printf("%d ", cut_point[i]);
        printf("%d\n", cut_point[k-1]);
    }
    sort(cut_edges, cut_edges+edge2_idx, edge_cmp);
    k = unique(cut_edges, cut_edges+edge2_idx, edge_equ) - cut_edges;
    for (int i = 0; i < k; ++i)
        printf("%d %d\n", cut_edges[i].a, cut_edges[i].b);
    return 0;
}
