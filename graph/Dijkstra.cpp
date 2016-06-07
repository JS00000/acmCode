#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 1007

using namespace std;

typedef pair<int,int>Pair;

int n, m;
int dis[MAXN];
int mp[MAXN][MAXN];
bool flag[MAXN];


int dijkstra(int start, int end)
{
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
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
    return dis[end];
}


int main(int argc, char const *argv[])
{
    freopen("graph.in", "r", stdin);
    cin >> n >> m;
    int a, b, w;
    for (int i = 0; i < n+1; ++i)
        for (int j = 0; j < m+1; ++j)
            mp[i][j] = INT_MAX;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> w;
        mp[a][b] = w;
    }
    cout << dijkstra(1, n) << endl;
    return 0;
}
