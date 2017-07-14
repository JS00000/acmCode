// Dijkstra
#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

#define maxn 1007
#define maxm 10007

using namespace std;

typedef pair<int,int>Pair;

int dis[maxn];
bool flag[maxn];

int n, m, edge_idx, s, t;
int head[maxn];
struct node
{
    int to, next, c;
}edges[maxm*10];

void add_edge(int u, int v, int c)
{
    edges[edge_idx].c = c;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    edge_idx = 0;
}


int dijkstra(int start, int end)
{
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    memset(flag,0,sizeof(flag));
    dis[start] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair> > q;
    q.push(make_pair(dis[start], start));
    while (!q.empty())
    {
        Pair top = q.top();
        q.pop();
        int now=top.second;
        if (flag[now]) continue;
        flag[now] = true;
        for (int k = head[now]; k != -1; k = edges[k].next)
            if (!flag[edges[k].to] && edges[k].c < dis[edges[k].to] - dis[now])
            {
                dis[edges[k].to] = dis[now] + edges[k].c;
                q.push(make_pair(dis[edges[k].to], edges[k].to));
            }
    }
    return dis[end];
}


int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    build_graph();
    cin >> n >> m >> s >> t;
    int a, b, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> w;
        add_edge(a, b, w);
        add_edge(b, a, w);
    }
    cout << dijkstra(s, t) << endl;
    return 0;
}
