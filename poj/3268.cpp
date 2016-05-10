#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 1007

using namespace std;

typedef pair<int,int>Pair;


int n, m, x;
int dis1[MAXN], dis2[MAXN];
int mp1[MAXN][MAXN], mp2[MAXN][MAXN];
bool flag[MAXN];


void dijkstra(int start, int dis[], int mp[][MAXN])
{
    for (int i = 1; i <= n; i++) dis[i] = 100000000;
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
            if ( (!flag[j]) && (mp[now][j] + dis[now] < dis[j]) )
            {
                dis[j] = dis[now] + mp[now][j];
                q.push(make_pair(dis[j], j));
            }
    }
}


int main(int argc, char const *argv[])
{
    cin >> n >> m >> x;
    int a, b, w;
    for (int i = 0; i < n+1; ++i)
        for (int j = 0; j < m+1; ++j)
        {
            mp1[i][j] = 100000000;
            mp2[i][j] = 100000000;
        }
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> w;
        mp1[a][b] = w;
        mp2[b][a] = w;
    }
    dijkstra(x, dis1, mp1);
    dijkstra(x, dis2, mp2);

    int maxr = 0;
    for (int i = 1; i <= n; i++)
        if (i != x && maxr < dis1[i] + dis2[i]) maxr = dis1[i] + dis2[i];

    cout << maxr << endl;
    return 0;
}
