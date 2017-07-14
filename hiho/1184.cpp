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

int stack[maxn];
int group[maxn], bridgeCnt;
void dfs(int u) {
    //记录dfs遍历次序
    static int counter = 0;
    static int top = 0;
    //初始化dfn与low
    dfn[u] = low[u] = ++counter;
    //将u加入栈
    stack[++top] = u;
    for(int k = head[u]; k != -1; k = edges[k].next) {
        int v = edges[k].to;
        //节点v未被访问，则(u,v)为树边
        if(!dfn[v]) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                // printf("bridge: %d %d\n", u, v);    // 该边是桥
                bridgeCnt++;
            }
        }
        //节点v已访问，则(u,v)为回边
        else if(v != parent[u]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u])
    {
        // 因为low[u] == dfn[u]，对(parent[u],u)来说有dfn[u] > dfn[ parent[u] ]，因此low[u] > dfn[ parent[u] ]
        // 所以(parent[u],u)一定是一个桥，那么此时栈内在u之前入栈的点和u被该桥分割开
        // 则u和之后入栈的节点属于同一个组
        // 将从u到栈顶所有的元素标记为一个组，并弹出这些元素。
        int i = top, idmin = u;
        while(stack[i] != u) idmin = min(idmin, stack[i--]);
        while(stack[top] != u)
            group[stack[top--]] = idmin;
        group[stack[top--]] = idmin;
    }
}

int main()
{
    build_graph();
    memset(dfn, 0, sizeof(dfn));
    NIL = parent[1] = -1, bridgeCnt = 0;
    dfs(1);
    printf("%d\n", bridgeCnt+1);
    for (int i = 1; i < n; ++i)
        printf("%d ", group[i]);
    printf("%d\n", group[n]);
    return 0;
}
