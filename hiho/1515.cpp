#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define maxn 100007
#define maxq 100007

using namespace std;

int p[maxn];
int head[maxn];
int qhead[maxn];
int dist[maxn];
struct node
{
    int to, w, next, lca;
}edge[maxn*2], qedge[maxq*2];

struct qnode
{
    int a, b;
}qq[maxq];

map<pair<int, int> , int> qmap;

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
bool visit[maxn];
bool tree[maxn];
void LCA(int u, int d)
{
    p[u] = u;
    dist[u] = d;
    int k;
    visit[u] = true;
    tree[u] = true;
    for (k = head[u]; k != 0; k = edge[k].next)
    {
        if (!tree[edge[k].to])
        {
            LCA(edge[k].to, d + edge[k].w);
            p[edge[k].to] = u;
        }
    }
    for (k = qhead[u]; k != 0; k = qedge[k].next)
        if (tree[qedge[k].to])
            qmap[make_pair(qedge[k].to, u)] = qmap[make_pair(u, qedge[k].to)] = find(qedge[k].to);
}

int main(int argc, char const *argv[])
{
    int n, m, q, a, b, w;
    cin >> n >> m >> q;
    memset(visit, 0, sizeof(visit));
    memset(head, 0, sizeof(head));
    memset(qhead, 0, sizeof(qhead));
    memset(dist, 0, sizeof(dist));
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> w;
        edge[i*2-1].to = b;
        edge[i*2-1].w = w;
        edge[i*2-1].lca = 0;
        edge[i*2-1].next = head[a];
        head[a] = i*2-1;
        edge[i*2].to = a;
        edge[i*2].w = -w;
        edge[i*2].lca = 0;
        edge[i*2].next = head[b];
        head[b] = i*2;
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b;
        qedge[i*2-1].to = b;
        qedge[i*2-1].next = qhead[a];
        qhead[a] = i*2-1;
        qedge[i*2].to = a;
        qedge[i*2].next = qhead[b];
        qhead[b] = i*2;
        qq[i].a = a;
        qq[i].b = b;
    }
    for (int i = 1; i <= n; ++i)
        if (!visit[i]) 
        {
            memset(tree, 0, sizeof(tree));
            LCA(i, 0);
        }
    for (int i = 1; i <= q; ++i)
    {
        if (!qmap.count(make_pair(qq[i].a, qq[i].b))) cout << "-1\n";
        else cout << dist[qq[i].b] - dist[qq[i].a] << endl;
    }
    return 0;
}