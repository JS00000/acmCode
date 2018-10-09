#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
#define maxm 1000007
using namespace std;

int n, m, edge_idx;
int head[maxn], indegree[maxn];
struct node
{
    int to, next;
}edges[maxm*2];

inline void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    memset(indegree, 0, sizeof(indegree));
    edge_idx = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int kk, t;
        scanf("%d", &kk);
        for (int k = 0; k < kk; k++) {
            scanf("%d", &t);
            add_edge(t, i);
            indegree[i]++;
        }
    }
}

int q[maxn], p[maxn], us[maxn];
void solve()
{
    int i = 0, iq = 0, ans = 0;
    for (int j = 0; j <= n; j++) {
        p[j] = 0;
        us[j] = 0;
    }
    for (int k = head[0]; k != -1; k = edges[k].next) {
        int t = edges[k].to;
        p[t] = 1;
        us[t] = t;
        ans++;
        q[iq++] = t;
    }
    while (i < iq) {
        int u = q[i];
        for (int k = head[u]; k != -1; k = edges[k].next) {
            int t = edges[k].to;
            if (--indegree[t] == 0) {
                q[iq++] = t;
            }
            if (!p[t]) {
                if (p[u]) {
                    if (us[t] == 0) {
                        us[t] = u;
                    } else if (us[t] != u){
                        p[t] = 1;
                        ans++;
                    }
                } else {
                    if (us[t] == 0) {
                        us[t] = us[u];
                    } else if (us[t] != us[u]){
                        p[t] = 1;
                        ans++;
                    }
                }
            }
        }
        i++;
    }
    printf("%d\n", ans);
}

int main()
{
    build_graph();
    solve();
    return 0;
}
