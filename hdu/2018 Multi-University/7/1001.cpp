#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
#define maxm 200007
using namespace std;

int n, m, edge_idx;
int head[maxn];
struct node
{
    int to, next, w;
}edges[maxm*2];

inline void add_edge(int u, int v, int w)
{
    edges[edge_idx].w = w;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    edge_idx = 0;
    int a, b, c;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
}


typedef pair<int,int>Pair;
int dist[maxn];
int inf = 0x7fffffff;
bool flag[maxn];
set<int> vs[maxn];

int dijkstra(int start, int end)
{
    for (int i = 1; i <= n; i++) 
        dist[i] = inf, vs[i].clear();
    memset(flag,0,sizeof(flag));
    dist[start] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair> > q;
    q.push(make_pair(dist[start], start));
    while (!q.empty()) {
        Pair top = q.top();
        q.pop();
        int now=top.second;
        if (flag[now]) continue;
        flag[now] = true;
        for (int k = head[now]; k != -1; k = edges[k].next) {
            if (vs[now].count(edges[k].w)) {
                if (dist[edges[k].to] >= dist[now]) {
                    dist[edges[k].to] = dist[now];
                    vs[edges[k].to].insert(edges[k].w);
                    q.push(make_pair(dist[edges[k].to], edges[k].to));
                }
            } else {
                if (!flag[edges[k].to] && dist[edges[k].to] > dist[now]) {
                    dist[edges[k].to] = dist[now] + 1;
                    vs[edges[k].to].insert(edges[k].w);
                    q.push(make_pair(dist[edges[k].to], edges[k].to));
                }
            }
        }
    }
    return dist[end];
}



int main()
{
    while (~scanf("%d%d", &n, &m)) {
        build_graph();
        if (dijkstra(1, n) == inf) printf("-1\n");
        else printf("%d\n", dist[n]);
    }
    return 0;
}
