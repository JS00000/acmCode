#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
#define maxm 1000007

using namespace std;


int N, W, H, edge_idx;
int head[maxn];
bool visit[maxn];
struct node
{
    int to, next;
}edges[maxm];
struct dot
{
    int x, y, r;
}points[maxn];

void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

bool dfs(int u)
{
    if (u == N+1) return 1;
    visit[u] = 1;
    for (int k = head[u]; k != -1; k = edges[k].next)
        if (!visit[edges[k].to])
            if (dfs(edges[k].to)) return 1;
    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &W, &H, &N);
        edge_idx = 0;
        memset(head, -1, (N+5)*sizeof(int));
        memset(visit, 0, (N+5)*sizeof(bool));
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d%d", &points[i].x, &points[i].y, &points[i].r);
            if (points[i].y <= points[i].r) add_edge(0, i), add_edge(i, 0);
            if (points[i].y + points[i].r >= H) add_edge(N+1, i), add_edge(i, N+1);
        }
        for (int i = 1; i < N; i++)
        {
            for (int j = i+1; j <= N; j++)
            {
                if (  (long long)(points[i].x - points[j].x)*(points[i].x - points[j].x) 
                     +(long long)(points[i].y - points[j].y)*(points[i].y - points[j].y) 
                    <=(long long)(points[i].r + points[j].r)*(points[i].r + points[j].r) )
                    add_edge(i, j), add_edge(j, i);
            }
        }
        printf("%s\n", dfs(0)?"NO":"YES");
    }
    return 0;
}

