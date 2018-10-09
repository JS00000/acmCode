#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
#define maxm 400007
using namespace std;
typedef long long ll;

int n, m, edge_idx;
int head[maxn];
struct node
{
    int to, next;
}edges[maxm];

inline void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

inline ll f(int x, int y)
{
    if (x < y) return (ll)x * n + y;
    else return (ll)y * n + x;
}

int du[maxn], back[maxn], visit[maxn];
set<ll> st;

void build_graph()
{
    int u, v, t, i;
    edge_idx = 0;
    st.clear();
    memset(du, 0, sizeof(int) * (n + 1));
    memset(head, -1, sizeof(int) * (n + 1));
    memset(back, -1, sizeof(int) * (n + 1));
    memset(visit, 0, sizeof(int) * (n + 1));
    for (i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
        du[u]++;
        du[v]++;
        st.insert(f(u, v));
    }
}

ll solve()
{
    int i, j, k, kk, mm = sqrt(m);
    ll ans = 0, sum;
    for (i = 1; i <= n; i++) {
        visit[i] = 1;
        for (k = head[i]; k != -1; k = edges[k].next) {
            back[edges[k].to] = i;
        }
        for (k = head[i]; k != -1; k = edges[k].next) {
            j = edges[k].to;
            if (visit[j]) continue;
            sum = 0;
            if (du[j] <= mm) {
                for (kk = head[j]; kk != -1; kk = edges[kk].next) {
                    if (back[edges[kk].to] == i) {
                        sum++;
                    }
                }
            } else {
                for (kk = head[i]; kk != -1; kk = edges[kk].next) {
                    if (st.find(f(j, edges[kk].to)) != st.end()) {
                        sum++;
                    }
                }
            }
            ans += sum * (sum-1) / 2;
        }
    }
    return ans;
}

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        build_graph();
        printf("%lld\n", solve());
    }
    return 0;
}
