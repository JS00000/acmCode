#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int lint;
#define maxn (100010)
struct node {
    int id;
    lint b;
    bool operator< (const node& o) const {
        return b < o.b;
    }
};
vector<node> nodes;
lint b[maxn], max_b, vis[maxn];
vector<int> to[maxn];
vector<int> sub;
void dfs(int u) {
    // printf("u = %d\n", u);
    vis[u] = 1;
    for(vector<int>::iterator it = to[u].begin(); it != to[u].end(); it++) {
        int v = *it;
        if(vis[v]) continue;
        if(b[v] == b[u]) {
            dfs(v);
        } else {
            if(b[v] > max_b) {
                max_b = b[v];
            }
            sub.push_back(v);
        }
    }
    b[u] = max_b;
    // printf("u = %d end\n", u);
}
bool cmp(int x, int y) {
    return b[x] > b[y];
}
int main()
{
    int T; cin >> T; while(T--) {
        int n, m; cin >> n >> m;
        nodes.clear();
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &b[i]);
            to[i].clear();
            vis[i] = 0;
            nodes.push_back((node){i, b[i]});
        }

        for(int i = 0; i < m; i++) {
            int u, v; scanf("%d%d", &u, &v);
            to[u].push_back(v);
            to[v].push_back(u);
        }    

        // printf("solve\n");
        lint ans = 0;
        sort(nodes.begin(), nodes.end());
        for(int i = nodes.size()-1; i >= 0; i--) {
            int u = nodes[i].id;
            // printf("check u = %d\n", u);
            if(vis[u]) continue;
            // printf("dfs u = %d\n", u);
            max_b = 0; sub.clear();
            dfs(u);
            // printf("dfs %d end, max_b = %d\n", u, max_b);
            ans += b[u] - max_b;

            // temp.clear();
            // for(set<int>::iterator it = sub.begin(); it != sub.end(); it++) {
            //     temp.push_back(*it);
            // }
            // // sort(temp.begin(), temp.end(), cmp);
            for(int j = 0, sz = sub.size(); j < sz -1; j++) {
                to[sub[j]].push_back(sub[j+1]);
                to[sub[j+1]].push_back(sub[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
// 1
// 3 2
// 3 5 4
// 1 2
// 2 3
