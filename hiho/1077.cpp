// 线段树
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int N = 1000007;

int top[N<<2];
void pushUP(int rt)
{
	top[rt] = min(top[rt<<1], top[rt<<1|1]);
}

void build(int l, int r, int rt)
{
	if (l == r)
	{
		scanf("%d", top+rt);
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushUP(rt);
}

void update(int p, int sc, int l, int r, int rt)
{
	if (l == r)
	{
		top[rt] = sc;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p, sc, lson);
	else update(p, sc, rson);
	pushUP(rt);
}

int query(int L, int R, int l, int r, int rt)
{
	if (L<=l && r<=R) return top[rt];
	int m = (l + r) >> 1;
	int ret = INT_MAX;
	if (L<=m) ret = min(ret, query(L, R, lson));
	if (R>m) ret = min(ret, query(L, R, rson));
	return ret;
}

int main(int argc, char const *argv[])
{
	// freopen("in.in", "r", stdin);
	int n, q, w;
	scanf("%d", &n);
	build(1, n, 1);
	scanf("%d", &q);
	int p, a, b;
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%d%d", &p, &a, &b);
		if (p == 0)
		{
			printf("%d\n", query(a, b, 1, n, 1));
		}
		else update(a, b, 1, n, 1);
	}
	return 0;
}
