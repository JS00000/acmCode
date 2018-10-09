#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define maxn 4007
#define maxm 10007

using namespace std;

int n, m, edge_idx, X;
int head[maxn];
struct node
{
    int to, next, w;
}edges[maxm];


void add_edge(int u, int v, int w)
{
    edges[edge_idx].to = v;
    edges[edge_idx].w = w;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

map<pair<int, int>, int> ee;
void add_map(int u, int v, int w)
{
    map<pair<int, int>, int>::iterator it = ee.find(make_pair(u, v));
    if (it != ee.end()) {
        w = min(w, it->second);
        it->second = w;
    } else {
        ee[make_pair(u, v)] = w;
    }
}

void build_graph()
{
    cin >> n >> m >> X;
    memset(head, -1, sizeof(head));
    edge_idx = 0;
    ee.clear();
    int A, B, C, D;
    for (int i = 1; i <= m; ++i)
    {
        cin >> A >> B >> C >> D;
        if (A == B && C == D) {
            add_map(A, C, X);
            add_map(C, A, -X);
        } else if (A == B) {
            if (C != A) 
                add_map(A, C, X - 1);
            add_map(D, A, - X - 1);
        } else if (C == D) {
            if (C != B) 
                add_map(B, C, X - 1);
            add_map(D, A, - X - 1);
        } else {
            if (C != B) 
                add_map(B, C, X - 1);
            add_map(D, A, - X - 1);
        }
    }
    add_map(0, 1, 0);
    for (int i = 2; i <= n; i++) {
        add_map(0, i, 0);
        add_map(i, i-1, -1);
    }
    for (map<pair<int, int>, int>::iterator it = ee.begin(); it != ee.end(); it++) {
        add_edge(it->first.first, it->first.second, it->second);
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int k = head[i]; k != -1; k = edges[k].next) {
    //         printf("%d %d %d\n", i, edges[k].to, edges[k].w);
    //     }
    // }
}

int inf = 0x7fffffff;
int dist[maxn];
bool SPFA(int s)
{
    bool visit[maxn];
    int queue[maxn];
    int outque[maxn];
    int iq = 0;
    for (int i = 0; i <= n; ++i)
        dist[i] = inf;
    memset(visit, 0, sizeof(visit));
    memset(outque, 0, sizeof(outque));
    queue[iq++] = s;
    visit[s] = 1;
    dist[s] = 0;
    int i = 0;
    while(i != iq)
    {
        int top = queue[i];
        visit[top] = 0;
        outque[top]++;
        if (outque[top] > n) return false;
        for (int k = head[top]; k != -1; k = edges[k].next)
        {
            if (dist[edges[k].to] - edges[k].w > dist[top])
            {
                dist[edges[k].to] = dist[top] + edges[k].w;
                // printf("%d ", dist[edges[k].to]);
                if (!visit[edges[k].to])
                {
                    visit[edges[k].to] = 1;
                    queue[iq++] = edges[k].to;
                    if (iq >= n + 1) iq = 0;
                }
            }
        }
        i++;
        if (i >= n + 1) i = 0;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    // freopen("1010.txt", "r", stdin);
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        build_graph();
        printf("Case #%d:", kase);
        if (!SPFA(0)) printf(" IMPOSSIBLE\n");
        else {
            for (int i = 2; i <= n; ++i)
                printf(" %d", dist[i] - dist[i - 1]);
            printf("\n");
        }
    }
    return 0;
}
