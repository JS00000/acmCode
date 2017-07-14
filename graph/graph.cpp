#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;



int n, m, edge_idx;
int head[maxn];
struct node
{
    int to, next, w;
}edges[maxm*10];

void add_edge(int u, int v, int w)
{
    edges[edge_idx].w = w;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    edge_idx = 0;
}

int main()
{
    return 0;
}

