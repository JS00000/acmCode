#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
#define maxm 1000007
using namespace std;

int edge_idx;
int head[maxn];
struct node
{
    int to, next;
}edges[maxm*10];

void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    edge_idx = 0;
}

int W, H, N;
int x1[maxn], x2[maxn], yy[maxn], y2[maxn];
bool hide[maxn][5];
bool p[maxn];

bool overlap(int i, int j)
{
    return !(x1[i] >= x2[j] || x1[j] >= x2[i] || yy[i] >= y2[j] || yy[j] >= y2[i]);
}

void dot_lap(int i, int j)
{
    hide[i][1] = hide[i][1] || (x1[j] < x1[i] && x1[i] < x2[j] && yy[j] < yy[i] && yy[i] < y2[j]);
    hide[i][2] = hide[i][2] || (x1[j] < x2[i] && x2[i] < x2[j] && yy[j] < yy[i] && yy[i] < y2[j]);
    hide[i][3] = hide[i][3] || (x1[j] < x2[i] && x2[i] < x2[j] && yy[j] < y2[i] && y2[i] < y2[j]);
    hide[i][4] = hide[i][4] || (x1[j] < x1[i] && x1[i] < x2[j] && yy[j] < y2[i] && y2[i] < y2[j]);
}

int bfs(int x)
{
    int ret = 1, q[maxn], iq = 1, i;
    bool p[maxn];
    for (i = 0; i < N; ++i) p[i] = 0;
    p[x] = 1;
    q[0] = x;
    i = 0;
    while(i < iq)
    {
        for (int k = head[q[i]]; k != -1; k = edges[k].next)
        {
            int e = edges[k].to;
            if (!p[e])
            {
                p[e] = 1;
                q[iq++] = e;
                ret++;
            }
        }
        i++;
    }
    return ret;
}

int main()
{
    scanf("%d%d%d", &W, &H, &N);
    for (int i = 0; i < N; ++i)
        scanf("%d%d%d%d", x1+i, yy+i, x2+i, y2+i);
    build_graph();
    memset(hide, 0, sizeof(hide));
    for (int j = 1; j < N; ++j)
    {
        for (int i = 0; i < j; ++i)
        {
            if (overlap(i, j)) add_edge(i, j);
            dot_lap(i, j);
        }
    }
    for (int i = 0; i < N; ++i)
        hide[i][0] = (hide[i][1] && hide[i][2] && hide[i][3] && hide[i][4]);
    int ma = 0, k;
    for (int i = 0; i < N; ++i)
        if (!hide[i][0])
        {
            int temp = bfs(i);
            if (temp > ma)
            {
                ma = temp;
                k = i;
            }
        }
    printf("%d %d\n", ma, k+1);
    return 0;
}
