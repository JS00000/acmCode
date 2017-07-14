// Prim
#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

#define MAXN 100007
#define MAXM 1000007

using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n, m;
int head[MAXN];
struct EdgeNode
{
    int to;
    int w;
    int next;
};
EdgeNode edge[MAXM];

void addEdge(int k, int i, int j, int w)
{
    edge[k].to = j;
    edge[k].w = w;
    edge[k].next = head[i];
    head[i] = k;
}

void graphCreat()
{
    n = read(), m = read();
    // std::ios::sync_with_stdio(false);
    // cin >> n >> m;
    memset(head, 0, (n+1)*sizeof(int));
    memset(edge, 0, (m*2+1)*sizeof(EdgeNode));
    int i, j, w;
    for (int k = 1; k <= m; ++k)
    {
        i = read(), j = read(), w = read();
        // cin >> i >> j >> w;
        addEdge(k*2-1, i, j, w);
        addEdge(k*2, j, i, w);
    }
}

const int MAXSIZE=100000;
struct BinaryHeap
{
    int heap[MAXSIZE], id[MAXSIZE], pos[MAXSIZE], n, counter;
    BinaryHeap():n(0), counter(0){}
    BinaryHeap(int array[], int offset):n(0), counter(0)
    {
        for (int i = 0; i < offset; ++i)
        {
            heap[++n] = array[i];
            id[n] = pos[n] = n;
        }
        for (int i = n/2; i >= 1; --i)
            down(i);
    }
    void push(int v)
    {
        heap[++n] = v;
        id[n] = ++counter;
        pos[id[n]] = n;
        up(n);
    }
    int top()
    {
        return heap[1];
    }
    int pop()
    {
        swap(heap[1], heap[n]);
        swap(id[1], id[n--]);
        pos[id[1]] = 1;
        down(1);
        return id[n+1];
    }
    int get(int i)
    {
        return heap[pos[i]];
    }
    int touch(int i)
    {
        return id[i];
    }
    void change(int i, int value)
    {
        heap[pos[i]] = value;
        down(pos[i]);
        up(pos[i]);
    }
    void erase(int i)
    {
        heap[pos[i]] = INT_MIN;
        up(pos[i]);
        pop();
    }
    void up(int i)
    {
        int x = heap[i], y = id[i];
        for (int j = i/2; j >= 1; j/=2)
        {
            if (heap[j]>x)
            {
                heap[i] = heap[j];
                id[i] = id[j];
                pos[id[i]] = i;
                i = j;
            }
            else break;
        }
        heap[i] = x;
        id[i] = y;
        pos[y] = i;
    }
    void down(int i)
    {
        int x = heap[i], y = id[i];
        for (int j = i*2; j <= n; j*=2)
        {
            j += j<n && heap[j]>heap[j+1];
            if (heap[j]<x)
            {
                heap[i] = heap[j];
                id[i] = id[j];
                pos[id[i]] = i;
                i = j;
            }
            else break;
        }
        heap[i] = x;
        id[i] = y;
        pos[y] = i;
    }
    bool empty()
    {
        return n==0;
    }
    bool size()
    {
        return n;
    }
};

int dist[MAXN];
void prim()
{
    BinaryHeap H;
    int i, j, k;
    bool p[MAXN] = {0};
    for (int i = 1; i <= n; ++i)
    {
        H.push(INT_MAX);
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    H.change(1, 0);
    for (i = 1;;)
    {
        p[i] = true;
        H.pop();
        for (int k = head[i]; k != 0; k = edge[k].next)
        {
            j = edge[k].to;
            if (!p[j] && edge[k].w < dist[j])
            {
                dist[j] = edge[k].w;
                H.change(j, dist[j]);
            }
        }
        if (H.size())
            i = H.touch(1);
        else break;
    }
}


int main(int argc, char const *argv[])
{
    graphCreat();
    prim();
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += dist[i];
    cout << ans << endl;
    return 0;
}
