// 前向星
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10001

using namespace std;

int head[MAXN];
struct NODE
{
    int from;
    int to;
    int w;
};

NODE edge[MAXN];

bool cmp(NODE a, NODE b)
{
    if (a.from==b.from && a.to==b.to) return a.w < b.w;
    if (a.from==b.from) return a.to < b.to;
    return a.from < b.from;
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> edge[i].from >> edge[i].to >> edge[i].w;
    }
    sort(edge, edge+m, cmp);
    memset(head, -1, sizeof(head));
    head[edge[0].from] = 0;
    for (int i = 1; i < m; ++i)
    {
        if (edge[i].from!=edge[i-1].from)
        {
            head[edge[i].from] = i;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int k = head[i]; edge[k].from == i && k < m ; ++k)
        {
            cout << edge[k].from << " " << edge[k].to << " " << edge[k].w << endl;
        }
    }
    cin >> n;
    return 0;
}
