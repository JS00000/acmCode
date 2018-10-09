#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define maxm 400007

using namespace std;

struct disjoint_set
{
    std::vector<int> father, rank;
    disjoint_set(int n) : father(n+1), rank(n+1)
    {
        for (int i = 0; i <= n; ++i)
            father[i] = i;
    }

    int find(int v)
    {
        return father[v] = father[v]==v ? v : find(father[v]);
    }

    void merge(int x, int y)
    {
        int a = find(x), b = find(y);
        if (rank[a] < rank[b]) {
            father[a] = b;
        } else {
            father[b] = a;
            if (rank[b]==rank[a])
                ++rank[a];
        }
    }
};

int n, m, mm;
long long tot;
struct edge_node
{
    int a, b, w;
} edges[maxm];

void build_graph()
{
    tot = 0;
    int u, v, w;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &u, &v);
    }
    memset(edges, 0, (m+1)*sizeof(edge_node));
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        edges[i].a = u;
        edges[i].b = v;
        edges[i].w = w;
        tot += w;
    }
}

bool cmp(edge_node a, edge_node b)
{
    return a.w > b.w;
}

long long kruskal()
{
    disjoint_set dis(n);
    sort(edges, edges+m, cmp);
    int x, y;
    long long ans = 0;
    mm = 0;
    for (int i = 0; i < m; ++i) {
        x = dis.find(edges[i].a);
        y = dis.find(edges[i].b);
        if (x != y) {
            dis.merge(x, y);
            ans += edges[i].w;
            mm++;
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &n, &m)) {
        build_graph();
        int ma = kruskal();
        printf("%d %lld\n", m - mm, tot - ma);
    }
    return 0;
}
