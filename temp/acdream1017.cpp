#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int inf = ~0u>>1;
#define MIN(a,b) (a)<(b)?(a):(b)
int n, m, K, s, t, S, T, N;
int head[30010],ef[30010],h[30010],idx;
bool mp[20][20], vis[30010]; 
struct Edge{
    int v, f, nxt;
}edge[500101];
struct node{
       int x;
       bool operator < (node tmp) const
       {
            return h[x] > h[ tmp.x ];
       }       
}qs,qt;
priority_queue< node > Q;
void AddEdge(int u, int v, int f)
{
    edge[idx].v = v; edge[idx].f = f;
    edge[idx].nxt = head[u]; head[u] = idx++;
    edge[idx].v = u; edge[idx].f = 0;
    edge[idx].nxt = head[v]; head[v] = idx++;
} 
void CreateGraph(int d)
{
    S = 0; T = (d+1)*n+1; N = (d+1)*n+2;
    memset(head,0xff,sizeof(head));idx = 0;    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if( mp[i][j] )    
                for(int c = 1; c <= d; c++)
                    AddEdge( (c-1)*n+j, c*n+i, 1 );
    for(int i = 1; i <= n; i++)
        for(int c = 1; c <= d; c++)
            AddEdge( (c-1)*n+i, c*n+i, inf );
    for(int c = 1; c <= d; c++)
        AddEdge( c*n+t, T, inf );
    AddEdge( S, s, K );
}
bool Preflow_push()
{
    int maxflow = 0;
    memset( ef, 0, sizeof(ef));
    memset( h, 0, sizeof(h));
    memset( vis, 0, sizeof(vis));    
    ef[S] = inf; h[S] = N; 
    while( !Q.empty() ) Q.pop();
    qs.x = S; Q.push( qs ); vis[S] = true;
    while( !Q.empty() )
    {
        int u = (Q.top()).x; Q.pop(); 
        vis[u] = false;
    //    printf(" u = %d,h[u] = %d\n", u, h[u] );
        for(int i = head[u]; ~i ; i = edge[i].nxt )
        {
            int v = edge[i].v;
            int p = MIN( ef[u], edge[i].f );    
            if( p > 0 && (u == S || h[u] == h[v]+1)  )//层次图 
            {    
                edge[i].f -= p; edge[i^1].f += p; //更新残留网络    
                ef[u] -= p; ef[v] += p; //更新节点盈余值
                if( v == T ) maxflow += p;
                if( !vis[v] && v != S && v != T ){
                    vis[v] = true; 
                    qt.x = v; Q.push(qt); 
                }
            }
        }
        if( ef[u] > 0 && u != S && u != T )
        {
                h[u]++;
                vis[u] = true;
                qt.x = u; Q.push(qt); 
        }
    }
    return (maxflow == K);
}

void input(){
    int u, v;
    memset( mp, 0, sizeof(mp));    
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d",&u,&v);
        mp[u][v] = mp[v][u] = true;
    }
}
void solve(){
    int l = 0, r = n*K;
    while( r > l ) //二分枚举天数
    {
        int mid = (r+l)>>1;
    //    printf("l = %d, r = %d, mid = %d\n", l, r, mid );    
        CreateGraph(mid);  
      //  l = r = mid;
        if( Preflow_push() ) r = mid;    
        else    l = mid+1;    
    }
    printf("%d\n", l );
}
int main(){
    while( scanf("%d%d%d%d%d", &n,&m,&K,&s,&t) != EOF)
    {
        input();
        solve();
    }
    return 0;
}
