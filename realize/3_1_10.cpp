// 半平面交
#include <iostream>
#include <cmath>
#include <complex>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

typedef complex<double> Point;
typedef pair<Point, Point> Halfplane;
const double EPS = 1e-10;
const double INF = 1e4;

inline int sgn(double n)
{
	return fabs(n) < EPS ? 0 : (n < 0 ? -1 : 1);
}
inline double cross(Point a, Point b)
{
	return (conj(a)*b).imag();
}
inline double dot(Point a, Point b)
{
	return (conj(a)*b).real();
}
inline bool satisfy(Point a, Halfplane p)
{
	return sgn(cross(a - p.first, p.second - p.first)) <= 0;
}

Point crosspoint(const Halfplane &a, const Halfplane  &b)
{
	double k = cross(b.first - b.second, a.first - b.second);
	k = k / (k - cross(b.first - b.second, a.second - b.second));
	return a.first + (a.second - a.first) * k;
}

bool cmp(const Halfplane &a, const Halfplane &b)
{
	int res = sgn(arg(a.second - a.first) - arg(b.second - b.first));
	return res == 0 ? satisfy(a.first, b) : res < 0;
}

vector<Point> halfplaneIntersection(vector<Halfplane> v)
{
	sort(v.begin(), v.end(), cmp);
	deque<Halfplane> q;
	deque<Point> ans;
	q.push_back(v[0]);
	for (int i = 1; i < int(v.size()); ++i)
	{
		if (sgn(arg(v[i].second - v[i].first) - arg(v[i-1].second - v[i-1].first)) == 0)
		{
			continue;
		}
		while (ans.size() > 0 && !satisfy(ans.back(), v[i]))
		{
			ans.pop_back();
			q.pop_back();
		}
		while (ans.size() > 0 && !satisfy(ans.front(), v[i]))
		{
			ans.pop_front();
			q.pop_front();
		}
		ans.push_back(crosspoint(q.back(), v[i]));
		q.push_back(v[i]);
	}
	while (ans.size() > 0 && !satisfy(ans.back(), q.front()))
	{
		ans.pop_back();
		q.pop_back();
	}
	while (ans.size() > 0 && !satisfy(ans.front(), q.back()))
	{
		ans.pop_front();
		q.pop_front();
	}
	ans.push_back(crosspoint(q.back(), q.front()));
	return vector<Point>(ans.begin(), ans.end());
}
int main(int argc, char const *argv[])
{
	Halfplane L1(Point(0,0), Point(1,1));
	Halfplane L2(Point(1,1), Point(0,2));
	Halfplane L3(Point(0,2), Point(-1,1));
	Halfplane L4(Point(-1,1), Point(-1,0));
	Halfplane L5(Point(0.5,0), Point(0.5,1));
	Halfplane L6(Point(0,0), Point(1,0));
	vector<Halfplane> v;
	v.push_back(L1);
	v.push_back(L2);
	v.push_back(L3);
	v.push_back(L4);
	v.push_back(L5);
	v.push_back(L6);
	vector<Point> ret = halfplaneIntersection(v);
	for (int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}
	return 0;
}