#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
vector<int>G[maxn];
int dp[maxn][maxn], g[maxn][maxn], a[maxn], N, K, ans;
void init(int n){
    for (int i=0;i<=n;i++) G[i].clear();
}

void dfs(int u){
    dp[u][1] = a[u];
    for (int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        dfs(v);
        for (int j = K ; j >= 1 ; j --)
        {
            for (int k = 1 ; k + j <= K ; k ++)
            {
                dp[u][j+k] = max (dp[u][j+k], dp[u][j] + dp[v][k]);
            }
        }
    }
    ans = max (ans, dp[u][K]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&K);
        init(N);
        for (int i=1;i<=N;i++) scanf("%d",&a[i]);
        for (int i=2;i<=N;i++){
            scanf("%d",&x);
            G[x].push_back(i);
        }
        memset(dp, 0 ,sizeof dp);
        ans = 0;
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
