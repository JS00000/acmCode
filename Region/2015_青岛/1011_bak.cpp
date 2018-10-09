// 设置源点st，汇点ed，清空head数组，添加边，tot=0

#include <cstdio>

using namespace std;

#define Clean(x) memset(x, 0, sizeof(x))


int tot = 0, st, ed;
int head[2007];
struct node
{
	int to, w, next;
}edge[20107];

void addedge(int x,int y,int z)
{
    edge[tot].w = z , edge[tot].to = y , edge[tot].next = head[x];
    head[x] = tot , tot++;
    edge[tot].w = 0 , edge[tot].to = x , edge[tot].next = head[y];
    head[y] = tot , tot++;
}
bool vis[maxn];
int dis[maxn];
void bfs()
{
    queue<int> q;
    Clean(dis,0);
    vis[st] = true , q.push(st);
    while( !q.empty() )
    {
        int u = q.front();
        q.pop();
        for( int k = head[u]; k != -1; k = edge[k].next )
            if ( edge[k].w && !vis[edge[k].to] )
            {
                q.push( edge[k].to );
                dis[edge[k].to] = dis[u] + 1;
                vis[edge[k].to] = true;
            }
    }
}
int dfs( int u , int delta )
{
    if ( u == ed ) return delta;
    int ret = 0;
    for( int k = head[u]; k != -1; k = edge[k].next )
        if ( edge[k].w && dis[edge[k].to] == dis[u] + 1 )
        {
            int dd = dfs( edge[k].to , min( delta , edge[k].w ) );
            edge[k].w -= dd;
            edge[k^1].w += dd;
            delta -= dd;
            ret += dd;
        }
    return ret;
}
int maxflow()
{
    int ret = 0;
    while(1)
    {
        Clean(vis,0);
        bfs();
        if ( !vis[ed] ) return ret;
        ret += dfs( st , inf );
    }
    return ret;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}