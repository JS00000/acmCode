// Tarjan
#include <map>
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
}edges[maxm*2];
map<pair<int, int>, int> mp;

void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    mp.clear();
    edge_idx = 0;
    n = read(), m = read();
    // scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read();
        // int a, b;
        // scanf("%d%d", &a, &b);
        mp[make_pair(min(a,b), max(a,b))] = edge_idx/2+1;
        add_edge(a, b);
        add_edge(b, a);
    }
}

int NIL, parent[maxn], low[maxn], dfn[maxn];

int edgeStack[maxn], top;
int group[maxm*2], group_min[maxm*2], group_idx;
bool eflag[maxm*2] = {}, visit[maxn] = {};

void pop(int eid)
{
    int nowEdge;
    group_min[group_idx] = maxm*2;
    do {
        group[nowEdge = edgeStack[--top]] = group_idx;
        group_min[group_idx] = min(group_min[group_idx], nowEdge);
        // printf("g2 u=%d v=%d now=%d top=%d group_idx=%d group_min=%d\n", u, v, nowEdge, top, group_idx, group_min[group_idx]);
    } while (nowEdge != eid);
    group_idx++;
}

void dfs(int u) {
    //记录dfs遍历次序
    static int counter = 0; 
    //记录节点u的子树数
    int children = 0;
    visit[u] = 1;
    //初始化dfn与low
    dfn[u] = low[u] = ++counter;
    for (int k = head[u]; k != -1; k = edges[k].next) {
        int v = edges[k].to;
        int eid = mp[make_pair(min(u,v), max(u,v))];
        if(eflag[eid]) continue; 
        //节点v未被访问，则(u,v)为树边
        if(!visit[v]) {
            children++;
            parent[v] = u;
            edgeStack[top++] = eid; // 将边入栈
            eflag[eid] = 1;
            dfs(v);
            low[u] = min(low[u], low[v]);
            //case (1)
            if(parent[u] == NIL && children > 1) {
                // printf("articulation point: %d\n", u);
                // mark edge
                // 将边出栈，直到当前边出栈为止，这些边标记为同一个组
                pop(eid);
            }
            //case (2)
            if(parent[u] != NIL && low[v] >= dfn[u]) {
                // printf("articulation point: %d\n", u);
                // mark edge
                // 将边出栈，直到当前边出栈为止，这些边标记为同一个组
                pop(eid);
            }
        }
        //节点v已访问，则(u,v)为回边
        else if(v != parent[u]) {
            edgeStack[top++] = eid;
            eflag[eid] = 1;
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main()
{
    build_graph();
    memset(dfn, 0, sizeof(dfn));
    NIL = parent[1] = -1;
    top = group_idx = 0;
    dfs(1);
    pop(edgeStack[0]);
    printf("%d\n", group_idx);
    for (int i = 1; i < m; i++)
        printf("%d ", group_min[group[i]]);
    printf("%d\n", group_min[group[m]]);
    return 0;
}
