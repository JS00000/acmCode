#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define maxn 100007
#define maxm 200007
using namespace std;

int n, m, edge_idx;
int head[maxn];
int dout[maxn];
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

void build_graph()
{
    memset(head, -1, sizeof(head));
    memset(dout, 0, sizeof(dout));
    edge_idx = 0;
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        dout[u]++;
    }
    for (int i = 1; i <= n; i++) {
        add_edge(i, i);
        dout[i]++;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    srand(time(0));
    int T;
    scanf("%d", &T);
    while (T--) {
        build_graph();
        int mtcl = 10000;
        int tot = 0;
        for (int i = 1; i <= mtcl; i++) {
            int now = 1, step = 0, sum = 0;
            while (now != n) {
                int r = rand() % dout[now];
                int k = head[now];
                while (r) {
                    k = edges[k].next;
                    r--;
                }
                now = edges[k].to;
                step++;
                sum += step;
            }
            tot += sum;
        }
        printf("%f\n", double(tot) / mtcl);
    }
    printf("%f\n", 4./3+8);
    return 0;
}
