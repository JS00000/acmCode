#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 50007
#define maxm 50007
typedef long long ll;
typedef pair<int,int>Pair;
using namespace std;

int n, m, q, edge_idx;
int head[maxn];
struct node
{
	int to, next;
	ll w;
}edges[maxm*2];

inline void add_edge(int u, int v, ll w)
{
	edges[edge_idx].w = w;
	edges[edge_idx].to = v;
	edges[edge_idx].next = head[u];
	head[u] = edge_idx++;
}

struct snode
{
	int k, i;
};

snode seq[maxn];

bool cmp(snode a, snode b) {
	return a.k < b.k;
}

ll dis[maxn];
priority_queue<Pair, vector<Pair>, greater<Pair> > q;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(head, -1, sizeof(head));
		edge_idx = 0;
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 0; i < m; i++) {
			int u, v;
			ll w;
			scanf("%d%d%lld", &u, &v, &w);
			add_edge(u, v, w);
		}
		int k;
		for (int i = 0; i < q; i++) {
			scanf("%d", &k);
			seq[i].k = k;
			seq[i].i = i;
		}
		sort(seq, seq+q, cmp);
		int ma = seq[q-1].k;
		int l = 0;
		q.clear();
		for (int i = 0; i < n; i++) {
			q.push(make_pair(0, i));
		}
		while (l < ma) {
			Pair top = q.top();
			q.pop();
			int now=top.second;
			for (int j = head[new]; j != -1; j = edges[j].next) {
				int to = edges[j].to;

				if ( (mp[now][j] < dis[j] - dis[now]) )
				{
					dis[j] = dis[now] + mp[now][j];
					q.push(make_pair(dis[j], j));
				}
			}
		}
	}
	return 0;
}
