#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


typedef unsigned long long LLU;
const LLU mod = 1000000007;
const int maxn = 5070;
const int maxm = 420070;


LLU n;
int m, edge_idx;
int head[maxn];
struct node
{
    int c, next, to;
}edges[maxm];

void add_edge(int u, int v, int c)
{
    edges[edge_idx].c = c;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void build_graph()
{
    memset(head, -1, sizeof(head));
    edge_idx = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++) {
                add_edge(i, j, (i-1)^(j-1));
                add_edge(j, i, 0);
        }
}


int sap_max_flow(int start, int end, int N)
{
    int numh[maxn], h[maxn], curedge[maxn], pre[maxn];
    // numh:用于GAP优化的统计高度数量数组; h:距离标号数组; curedge:当前弧数组; pre:前驱数组
    int cur_flow, flow_ans = 0, u, tmp, neck, i;
    memset(h, 0, sizeof(h));
    memset(numh, 0, sizeof(numh));
    memset(pre, -1, sizeof(pre));
    for (i = 1; i <= N; ++i)
        curedge[i] = head[i];
    numh[0] = N;
    u = start;
    while(h[start] < N)
    {
        if (u == end)
        {
            cur_flow = ~0u>>1;
            for (i = start; i != end; i = edges[curedge[i]].to)
            {
                if (cur_flow > edges[curedge[i]].c)
                {
                    neck = i;
                    cur_flow = edges[curedge[i]].c;
                }
            }
            for (i = start; i != end; i = edges[curedge[i]].to)
            {
                tmp = curedge[i];
                edges[tmp].c -= cur_flow;
                edges[tmp^1].c += cur_flow;
            }
            flow_ans += cur_flow;
            u = neck;
        }
        for (i = curedge[u]; i != -1; i = edges[i].next)
            if (edges[i].c && h[u]==h[edges[i].to]+1) break;
        if (i != -1)
        {
            curedge[u] = i;
            pre[edges[i].to] = u;
            u = edges[i].to;
        }
        else
        {
            if (0 == --numh[h[u]]) break; //GAP优化
            curedge[u] = head[u];
            for (tmp = N, i = head[u]; i != -1; i = edges[i].next)
                if (edges[i].c) tmp = min(tmp, h[edges[i].to]);
            h[u] = tmp + 1;
            ++numh[h[u]];
            if (u != start) u = pre[u];
        }
    }
    return flow_ans;
}



LLU multi(LLU a,LLU b,LLU p)   //大数 （a×b）%p
{
    LLU ret=0;
    while(b)
    {
        if(b&1)
            ret=(ret+a)%p;
            a=(a+a)%p;  //a*2^0  a*2^1  a*2^2  a*2^4
            b>>=1;
    }
    return ret;
}


LLU g( LLU n )
{
    LLU bit[100];
    LLU len = 0;
    LLU ans = 0;
    LLU temp = n;
    while(temp)
        bit[++len] = temp&1 , temp>>=1;
    LLU p = 2;
    for( LLU i = 1 ; i <= len; i++ , p<<=1 ) {
        ans = (ans + (p/2) * (((n+1)/p*(p/2)) % mod) % mod) % mod;
        if ( bit[i] == 1 ) {
            ans = (ans + (p/2) * min( (n+1)%p , p/2 ) % mod) % mod;
        }
        else {
            if ((n+1) %p > (p/2))
                ans = (ans + (p/2) * ((n+1) %p - (p/2)) % mod) % mod;
        }
    }
    return ans;
}

LLU f()
{
    LLU x = 1, sum = 0;
    while (x < n/2.) x *= 2;
    if (x > 1) sum = multi(x/2, x-1, mod);
    sum = (g(n-x-1) + sum) % mod;
    sum = (sum + n - 1) % mod;
    return sum;
}

int main()
{
    for (n = 2; n < 100; n++) {
        build_graph();
        int ans = sap_max_flow(1, n, n);
        LLU fa = f();
        printf("%llu %d %llu\n", n, ans, fa);
        if (ans != fa) printf("bad!\n");
    }
    return 0;
}
