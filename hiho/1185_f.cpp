#include <iostream>
#include <cstdio>
using namespace std;

inline int getint()
{
    char c;
    while ((c = getchar()) < '0' || c > '9');

    int res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9')
        res = res * 10 + c - '0';
    return res;
}

inline void tense(int &a, const int &b)
{
    if (b < a)
        a = b;
}
inline void relax(int &a, const int &b)
{
    if (b > a)
        a = b;
}

const int MaxN = 20005;
const int MaxM = 100005;

int n, m;
int w[MaxN], newW[MaxN];

struct halfEdge
{
    int v;
    halfEdge *next;
};
halfEdge adj_pool[MaxM], *adj_tail = adj_pool;
halfEdge *oriG[MaxN], *adj[MaxN];

inline void addEdge(halfEdge **adj, const int &u, const int &v)
{
    adj_tail->v = v, adj_tail->next = adj[u];
    adj[u] = adj_tail++;
}

int dfsCur = 0;
int dfn[MaxN], low[MaxN];

int nScc = 0;
int sccNum[MaxN];

int sta_n = 0, sta[MaxN];

void dfs(const int &u)
{
    low[u] = dfn[u] = ++dfsCur;
    sta[++sta_n] = u;

    for (halfEdge *e = oriG[u]; e; e = e->next)
    {
        if (!dfn[e->v])
        {
            dfs(e->v);
            tense(low[u], low[e->v]);
        }
        else if (!sccNum[e->v])
            tense(low[u], dfn[e->v]);
    }

    if (low[u] == dfn[u])
    {
        ++nScc;
        int v;
        do
        {
            v = sta[sta_n--];
            newW[sccNum[v] = nScc] += w[v];
        }
        while (v != u);
    }
}

int f[MaxN];

int calcF(const int &u)
{
    if (f[u])
        return f[u];
    for (halfEdge *e = adj[u]; e; e = e->next)
        relax(f[u], calcF(e->v));
    return f[u] += newW[u];
}

int main()
{
    cin >> n >> m;
    for (int u = 1; u <= n; ++u)
        w[u] = getint();
    while (m--)
    {
        int u = getint(), v = getint();
        addEdge(oriG, u, v);
    }

    for (int u = 1; u <= n; ++u)
        if (!sccNum[u])
            dfs(u);
    for (int u = 1; u <= n; ++u)
        for (halfEdge *e = oriG[u]; e; e = e->next)
            if (sccNum[u] != sccNum[e->v])
                addEdge(adj, sccNum[u], sccNum[e->v]);

    cout << calcF(sccNum[1]);

    return 0;
}