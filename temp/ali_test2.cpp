#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,j,k) for( int i = j; i <= k; i++ )

const int maxn = 20009;

int n , m;
vector<int> edge[maxn];
int dfn[maxn] , low[maxn] , root[maxn];
bool vis[maxn];

vector<int> ans;

void init()
{
    int a , b;
    cin>>n>>m;
    rep(i,1,n) edge[i].clear() , vis[i] = true , root[i] = -1;
    ans.clear();
    rep(i,1,m)
    {
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

void dfs( int u )
{
    static int tot = 0;
    dfn[u] = low[u] = ++tot;

    vis[u] = false;
    int cnt = 0;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if ( vis[v] )
        {
            root[v] = u;
            cnt++;
            dfs( v );
            low[u] = min( low[u] , low[v] );
            if ( root[u] == -1 && cnt > 1 ) ans.push_back(u);
            if ( root[u] != -1 && low[v] >= dfn[u] ) ans.push_back(u);
        }
        else if ( root[u] != v )
            low[u] = min( low[u] , dfn[v] );
    }
}


int main()
{
    init();
    dfs(1);
    sort(ans.begin(), ans.end());
    int k = unique( ans.begin() , ans.end() ) - ans.begin();
    if (ans[0] != 1) printf("1 ");
    rep(i,0,k-1) printf("%d ",ans[i]);
    if (ans[k-1] != n) printf("%d", n);
    printf("\n");
    return 0;
}
