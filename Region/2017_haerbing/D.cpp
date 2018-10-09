#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
#define maxm 1007
using namespace std;

int n, m, edge_idx, edge_idx2;
int head[maxn], head2[maxn];
struct node
{
    int to, next;
}edges[maxm*2], edges2[maxm*2];
bool man[maxn], vis[maxn], vis2[maxn];
int N, M;
int dis[maxn];

inline void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

inline void add_edge2(int u, int v)
{
    edges2[edge_idx2].to = v;
    edges2[edge_idx2].next = head2[u];
    head2[u] = edge_idx2++;
}


int dfs(int x) 
{
    int ma = 0;
    if (man[x]) ma = 1;
    vis[x] = 1;
    for (int k = head[x]; k != -1; k = edges[k].next) {
        if (!vis[edges[k].to]) {
            int d = dfs(edges[k].to);
            if (d > 0) {
                ma = max(ma, d + 1);
                add_edge2(x, edges[k].to);
                add_edge2(edges[k].to, x);
            }
        }
    }
    return ma;
}

void dfs2(int x)
{
    for (int k = head2[x]; k != -1; k = edges2[k].next) {
        if (!vis2[edges2[k].to]) {
            dis[edges2[k].to] = dis[x] + 1;
            vis2[edges2[k].to] = 1;
            dfs2(edges2[k].to);
        }
    }
}

int getD(int x, int &u)
{
    memset(dis, 0, sizeof(int) * (N + 1));
    memset(vis2, 0, sizeof(bool) * (N + 1));
    dis[x] = 0;
    vis2[x] = 1;
    dfs2(x);
    int ma = 0;
    for (int i = 1; i <= N; i++) {
        if (dis[i] > ma) {
            ma = dis[i];
            u = i;
        }
    }
    return ma;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        memset(vis, 0, sizeof(bool) * (N + 1));
        memset(man, 0, sizeof(bool) * (N + 1));
        int temp;
        for (int i = 0; i < M; i++) {
            scanf("%d", &temp);
            man[temp] = 1;
        }
        memset(head, -1, sizeof(head));
        memset(head2, -1, sizeof(head2));
        edge_idx = 0;
        edge_idx2 = 0;
        int u, v;
        for (int i = 0; i < N - 1; i++) {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        vis[temp] = 1;
        for (int k = head[temp]; k != -1; k = edges[k].next) {
            if (dfs(edges[k].to) > 0) {
                add_edge2(temp, edges[k].to);
                add_edge2(edges[k].to, temp);
            }
        }
        getD(temp, u);
        printf("%d.00\n", getD(u, v) / 2);
    }
    return 0;
}
