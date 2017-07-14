// Prim
#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

#define MAXN 1007
using namespace std;

int n;
int mp[MAXN][MAXN];

inline int getc(){
    static char buf[1<<15],*S=buf,*T=buf;
    if(S==T)if(T=(S=buf)+fread(buf,1,1<<15,stdin),S==T)return 0;
    return*S++;
}
int aa,ch;inline int F(){
    while(ch=getc(),ch<48||ch>57){};aa=ch-48;
    while(ch=getc(),ch>47&&ch<58)aa=aa*10+ch-48;return aa;
}

void graphCreat()
{
    n = F();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            mp[i][j] = F();
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

        for (int j = 1; j <= n; ++j)
        {
            if (!p[j] && mp[i][j] < dist[j])
            {
                dist[j] = mp[i][j];
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
