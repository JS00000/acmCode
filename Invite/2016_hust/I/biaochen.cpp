// GoogleCodeJam.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long LL;
const int NN = 100005;
const double eps = 1e-8;
int sgn(double x) { return (x < -eps) ? -1 : (x > eps); }

int idx;

struct NODE {
	static const int KD = 2;
	int id;
	double x[KD], dis;
	void read(int m) { for (int i = 0; i < m; i++) cin >> x[i]; }
	void show(int m) { for (int i = 0; i < m; i++) printf("%f%c", x[i], i == m - 1 ? '\n' : ' '); }
	bool operator < (const NODE &o) const { return x[idx] < o.x[idx] - eps; }
}	tmp;

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT(NODE& o) : x(o.x[0]), y(o.x[1]) {};
	PT operator + (const PT o) { return PT(x + o.x, y + o.y); }
	PT operator / (double s) { return PT(x / s, y / s); }
	bool operator < (const PT &o) const { return y < o.y - eps || (y < o.y + eps && x < o.x - eps); }
	bool operator == (const PT &o) const { return !sgn(y - o.y) && !sgn(x - o.x); }
	bool operator != (const PT &o) const { return sgn(y - o.y) || sgn(x - o.x); }
	static PT makeByNode(NODE o[], int m)
	{
		PT ret(0, 0);
		for (int i = 0; i < m; i++) ret = ret + PT(o[i]);
		return ret / m;
	}
	NODE PT2NODE()
	{
		NODE ret;
		ret.x[0] = x;
		ret.x[1] = y;
		return ret;
	}
};

struct KDT
{
	static const int M = 100005;
	int mark[M], spt[M], D;
	NODE tre[M], ret;
	void clear() { memset(mark, 0, sizeof(mark)); }
	template <class TP> TP sqr(TP x) { return x * x; }
	void build(int l, int r, int cut)
	{
		if (l > r) return;
		int mid = (l + r) / 2;
		idx = spt[mid] = cut;
		nth_element(tre + l, tre + mid, tre + r + 1);
		build(l, mid - 1, (cut + 1) % D);
		build(mid + 1, r, (cut + 1) % D);
	}
	void query(int l, int r, NODE &o)
	{
		if (l > r) return;
		int mid = (l + r) / 2;
		double dis = 0;
		for (int i = 0; i < D; i++) dis += sqr(o.x[i] - tre[mid].x[i]);

		if (mark[tre[mid].id] == 0 && dis < o.dis - eps) o.dis = dis, ret = tre[mid];

		double rad = sqr(o.x[spt[mid]] - tre[mid].x[spt[mid]]);
		if (o.x[spt[mid]] < tre[mid].x[spt[mid]] - eps)
		{
			if (query(l, mid - 1, o), rad < o.dis + eps) query(mid + 1, r, o);
		}
		else
		{
			if (query(mid + 1, r, o), rad < o.dis + eps) query(l, mid - 1, o);
		}
	}
}	kdt;


struct ANSDATA
{
	ANSDATA() {};
	ANSDATA(PT p, PT ffp, double d) : pt(p), fakeFermatPoint(ffp), distSum(d) {}
	PT fakeFermatPoint;
	PT pt;
	double distSum;
};

ANSDATA work(NODE p, int n)
{
	// use kd-tree for 12 
	NODE pp[12];
	for (int j = 0; j < 12; j++)
	{
		p.dis = 1e9;
		kdt.query(0, n - 1, p);
		pp[j] = kdt.ret;
		pp[j].dis = p.dis;
		kdt.mark[pp[j].id] = 1;
	}

	double ans = 0;
	for (int j = 0; j < 12; j++)
	{
		ans += sqrt(pp[j].dis);
		kdt.mark[pp[j].id] = 0;
	}

	ANSDATA ret;
	ret.fakeFermatPoint = PT::makeByNode(pp, 12);
	ret.distSum = ans;
	return ret;
};

// divide one point to 4 sub point.
void makeCandidatePt(vector <PT> &vcp, PT& o, double range, double step)
{
	for (double x = o.x - range + step * 0.5; x < o.x + range + eps; x += step)
		for (double y = o.y - range + step * 0.5; y < o.y + range + eps; y += step)
			vcp.emplace_back(PT(x, y));
}

double globleans;
PT bpt;
void checkCandidatePt(vector <PT> &vcp, double step, int n, vector <PT> &newvcp)
{
	map <PT, vector<ANSDATA>> mp;
	for (auto& it : vcp)
	{
		ANSDATA tmp = work(it.PT2NODE(), n);
		tmp.pt = it;
		mp[tmp.fakeFermatPoint].push_back(tmp);
	}

	double greatImpact = step * step * 6;
	for (auto& m : mp)
	{
		sort(m.second.begin(), m.second.end(), [](ANSDATA& a, ANSDATA&b) {return a.distSum < b.distSum - eps; });
		int count = 0;
		for (auto& j : m.second)
		{
			// keep 10% approximate ans point
			if (j.distSum > greatImpact * 1.1 + globleans) continue;
			newvcp.emplace_back(j.pt);

			if (globleans >  j.distSum)
			{
				globleans = j.distSum;
				bpt = j.pt;
			}

			// keep the top best 3 point
			if (++count == 3) break;
		}
	}
	
	/* debug
	printf("globleans = %.6f, newvcp size = %zu, greatImpact = %.6f\n", globleans, newvcp.size(), greatImpact);
	printf("(%.6f, %.6f)\n", bpt.x, bpt.y);
	*/
}

int main()
{
	/*
	freopen("d:\\easyac\\in4.txt", "r", stdin);
	freopen("d:\\easyac\\out5.txt", "w", stdout);
	*/
	int T;
	cin >> T;
	kdt.D = 2;

	for (int cas = 1; cas <= T; cas++)
	{
		int n;
		cin >> n;

		globleans = 1e9;
		for (int i = 0; i < n; i++) kdt.tre[i].read(2), kdt.tre[i].id = i, kdt.tre[i];
		kdt.build(0, n - 1, 0);
		
		vector <PT> vcp[2];
		vcp[0].emplace_back(PT(0, 0));

		int nn = 2;
		for (double range = 100; range > 1e-6; range /= nn)
		{
			double step = range * 2 / nn;
			vcp[1].clear();
			for (auto& it : vcp[0]) makeCandidatePt(vcp[1], it, range, step);

			vcp[0].clear();
			checkCandidatePt(vcp[1], step, n, vcp[0]);
		}
		printf("Case #%d: %.4f\n", cas, globleans);
	}
    return 0;
}

