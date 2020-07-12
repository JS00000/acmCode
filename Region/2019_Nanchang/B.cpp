#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define maxn 1007
#define inf (100000007)
using namespace std;

typedef pair<int,int>Pair;
int n, m, s, k, c;
int dis[maxn];
int team[maxn];
int mp[maxn][maxn];
bool flag[maxn];

int dijkstra(int start)
{
    for (int i = 1; i <= n; i++) dis[i] = inf;
    memset(flag,0,sizeof(flag));
    dis[start] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair> > q;
    q.push(make_pair(dis[start], start));
    while (!q.empty())
    {
        Pair top = q.top();
        q.pop();
        int now=top.second;
        if (flag[now]) continue;
        flag[now] = true;
        for (int j = 1; j <= n; j++)
            if ( (!flag[j]) && (mp[now][j] < dis[j] - dis[now]) )
            {
                dis[j] = dis[now] + mp[now][j];
                q.push(make_pair(dis[j], j));
            }
    }
    int maxi = 0;
    for (int i = 1; i <= n; i++) {
        maxi = max(maxi, dis[i]);
    }
    return maxi;
}


int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d", &n, &m, &s, &k, &c);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                mp[i][j] = inf;
            }
        }
        for (int i = 0; i < k; i++) {
            scanf("%d", team+i);
        }
        int u, v, l;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &l);
            mp[u][v] = min(mp[u][v], l);
            mp[v][u] = min(mp[v][u], l);
        }
        int maxs = dijkstra(s);
        for (int i = 1; i < k; i++) {
            mp[team[0]][team[i]] = 0;
            mp[team[i]][team[0]] = 0;
        }
        int maxt = dijkstra(team[0]);
        if (maxs <= maxt * c) printf("%d\n", maxs);
        else printf("%d\n", maxt);
    }
    return 0;
}
