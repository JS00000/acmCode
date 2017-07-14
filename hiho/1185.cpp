#include <set>
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
int head[maxn], head2[maxn];
struct node
{
    int to, next;
}edges[maxm*3];

int w[maxn], wn[maxn];
int low[maxn], stack[maxn];
int group[maxn] = {}, dfn[maxn] = {}, f[maxn] = {}, group_cnt = 0;

void add_edge(int h[], int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = h[u];
    h[u] = edge_idx++;
}

void build_graph()
{
    n = read(), m = read();
    memset(head, -1, (n+1)*sizeof(int));
    edge_idx = 0;
    int a, b;
    for (int i = 1; i <= n; ++i) 
        w[i] = read();
    for (int i = 0; i < m; ++i)
    {
        a = read(), b = read();
        add_edge(head, a, b);
    }
}

void tarjan(int u) {
    static int top = 0;
    static int counter = 0;
    dfn[u] = low[u] = ++counter;                                // 为节点u设定次序编号和Low初值
    stack[++top] = u;                                           // 将节点u压入栈中
    for(int k = head[u]; k != -1; k = edges[k].next) {          // 枚举每一条边
        int v = edges[k].to;
        if(!dfn[v]) {                                           // 如果节点v未被访问过
            tarjan(v);                                          // 继续向下找
            low[u] = min(low[u], low[v]);
        }
        else if(!group[v])                                      // 如果节点v还在栈内(很重要,无向图没有这一步)
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])                                       // 如果节点u是强连通分量的根
    {
        group_cnt++;
        do wn[group[stack[top]] = group_cnt] += w[stack[top]];  // 标记v，同样通过栈来找连通分量
        while (stack[top--] != u);                              // 将v退栈，为该强连通分量中一个顶点
    }
}

void build_graph2()
{
    memset(head2, -1, (group_cnt+1)*sizeof(int));
    set<pair<int, int> > edge_set;
    for (int i = 1; i <= n; ++i)
        for (int k = head[i]; k != -1; k = edges[k].next)
            if (group[i] != group[edges[k].to])
                edge_set.insert(make_pair(group[i], group[edges[k].to]));
    for (std::set<pair<int, int> >::iterator it = edge_set.begin(); it != edge_set.end(); ++it)
        add_edge(head2, it->first, it->second);
}

int dfs(int u)
{
    if (f[u]) return f[u];
    for (int k = head2[u]; k != -1; k = edges[k].next)
        f[u] = max(f[u], dfs(edges[k].to));
    return f[u] + wn[u];
}

int main()
{
    build_graph();
    for (int i = 1; i <= n; ++i)
        if (!group[i]) tarjan(i);
    build_graph2();
    printf("%d\n", dfs(group[1]));
    return 0;
}
