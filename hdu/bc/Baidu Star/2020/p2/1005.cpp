#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#define maxn 100000
#define maxm 310007
using namespace std;

const int inf = 0x3f3f3f3f;

int n, m, edge_idx;
int head[maxn];
struct node
{
    int to, next, c, w;
}edges[maxm*2];

void add_edge(int u, int v, int c, int w)
{
    edges[edge_idx].c = c;
    edges[edge_idx].w = w;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}


int dis[maxn], load[maxn], pre[maxn];
bool flag[maxn];
// dis:距离数组, load:前驱边, pre:前驱点
// flag:点是否入队
bool spfa(int start, int end, int N)
{
    int que[maxn*10], qout, qin;
    memset(flag, 0, sizeof(flag));
    memset(load, -1, sizeof(load));
    memset(pre, -1, sizeof(pre));
    for (int i = 0; i <= N; i++) dis[i] = inf;
    qin = qout = 0;
    que[qin++] = start;
    dis[start] = 0;
    flag[start] = 1;
    while(qin != qout)
    {
        int e = que[qout++];
        flag[e] = false;
        for (int k = head[e]; k != -1; k = edges[k].next)
        {
            if (edges[k].c)
            {
                int ne = edges[k].to;
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
    if (dis[end] == inf) return 0;
    return 1;
}

int min_cost_flow(int start, int end, int N)
{
    int u, mini, ans_flow = 0, ans_cost = 0;
    while(spfa(start, end, N))
    {
        u = end;
        mini = inf;
        while(pre[u] != -1)
        {
            mini = min(mini, edges[load[u]].c);
            u = pre[u];
        }
        u = end;
        while(pre[u] != -1)
        {
            edges[load[u]].c -= mini;
            edges[load[u]^1].c += mini;
            u = pre[u];
        }
        ans_cost += dis[end]*mini;
        ans_flow += mini;
    }
    return ans_cost;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        edge_idx = 0;
        memset(head, -1, sizeof(head));
        map<string, int> sm;
        int a, b, c;
        cin >> n >> a >> b >> c;
        add_edge(1, 5, a, 0);
        add_edge(5, 1, 0, 0);
        add_edge(2, 5, b, 0);
        add_edge(5, 2, 0, 0);
        add_edge(3, 5, c, 0);
        add_edge(5, 3, 0, 0);
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            if (!sm.count(s)) sm[s] = 1;
            else sm[s]++;
        }
        int nid = 0;
        for (std::map<string, int>::iterator i = sm.begin(); i != sm.end(); ++i)
        {
            int f[3];
            string s = i->first;
            for (int j = 0; j < 3; j++) {
                f[s[j] - '0'] = 3-j;
            }
            for (int j = 0; j < 3; j++) {
                add_edge(6+nid,j+1,i->second,-f[j]);
                add_edge(j+1,6+nid,0,f[j]);
            }
            add_edge(4, 6+nid, i->second, 0);
            add_edge(6+nid, 4, 0, 0);
            nid++;
        }
        cout << -min_cost_flow(4, 5, 5+nid) << endl;
    }
    return 0;
}
