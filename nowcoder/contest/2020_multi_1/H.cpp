// 费用流
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 67
#define maxm 207
using namespace std;

typedef long long ll;

ll n, m, edge_idx;
ll head[maxn];
struct node
{
    ll to, next, c, w;
}edges[maxm*4];

void add_edge(ll u, ll v, ll c, ll w)
{
    // c: capacity
    // w: weight
    edges[edge_idx].c = c;
    edges[edge_idx].w = w;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

ll load[maxn], pre[maxn], flow_id;
ll dis[maxn], ans_cost[maxm*4];
bool flag[maxn];
// dis:距离数组, load:前驱边, pre:前驱点
// flag:点是否入队
bool spfa(ll start, ll end, ll N)
{
    ll que[maxn*10], qout, qin;
    memset(flag, 0, sizeof(flag));
    memset(load, -1, sizeof(load));
    memset(pre, -1, sizeof(pre));
    for (ll i = 0; i <= N; i++) dis[i] = ~0ul>>1;
    qin = qout = 0;
    que[qin++] = start;
    dis[start] = 0;
    flag[start] = 1;
    while(qin != qout)
    {
        ll e = que[qout++];
        flag[e] = false;
        for (ll k = head[e]; k != -1; k = edges[k].next)
        {
            if (edges[k].c)
            {
                ll ne = edges[k].to;
                if (dis[ne] - dis[e] > edges[k].w)
                {
                    dis[ne] = dis[e] + edges[k].w;
                    pre[ne] = e;
                    load[ne] = k;
                    if (!flag[ne])
                    {
                        flag[ne] = 1;
                        que[qin++] = ne;
                    }
                }
            }
        }
    }
    if (dis[end] == ~0ul>>1) return 0;
    return 1;
}

void min_cost_flow(ll start, ll end, ll N)
{
    ll u;
    ans_cost[0] = 0;
    flow_id = 0;
    while(spfa(start, end, N))
    {
        u = end;
        while(pre[u] != -1)
        {
            edges[load[u]].c -= 1;
            edges[load[u]^1].c += 1;
            u = pre[u];
        }
        ans_cost[flow_id+1] = ans_cost[flow_id] + dis[end];
        flow_id++;
    }

}

ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b, a%b);
}

int main()
{
    while (~scanf("%lld%lld", &n, &m)) {
        memset(head, -1, sizeof(head));
        edge_idx = 0;
        for (ll i = 0; i < m; i++) {
            ll a, b, k;
            scanf("%lld%lld%lld",&a, &b, &k);
            add_edge(a,b,1,k);
            add_edge(b,a,0,-k);
            // add_edge(b,a,1,k);
            // add_edge(a,b,0,-k);
        }
        min_cost_flow(1, n, n);
        ll q;
        scanf("%lld", &q);
        for (ll j = 0; j < q; j++) {
            ll u, v, uu, vv, guv;
            scanf("%lld%lld", &u, &v);
            // scanf("%lld%lld", &uu, &vv);
            // guv = gcd(uu, vv);
            // u = uu / guv;
            // v = vv / guv;
            if (flow_id * u < v) {
                printf("NaN\n");
            } else {
                ll ans = u * ans_cost[(v / u)];
                ans += (v % u) * (ans_cost[(v / u) + 1] - ans_cost[(v / u)]);
                ll gg = gcd(ans, v);
                printf("%lld/%lld\n", ans/gg, v/gg);
                // printf("%lld/%lld\n", ans, v);
            }
        }
    }
    return 0;
}
