// 凸多边形交
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

typedef vector<Point> Convex;
Convex convexIntersection(Convex v1, Convex v2)
{
	vector<Halfplane> h, h1, h2;
	for (int i = 0; i < v1.size(); ++i)
		h1.push_back(Halfplane(v1[i], v1[(i+1)%v1.size()]));
	for (int i = 0; i < v2.size(); ++i)
		h2.push_back(Halfplane(v2[i], v2[(i+1)%v2.size()]));
	int p1 = 0, p2 = 0;
	while(p1 < h1.size() && p2 < h2.size())
	{
		int res = sgn(arg(h1[p1].second - h1[p1].first) - arg(h2[p2].second - h2[p2].first));
		if (res < 0)
			h.push_back(h1[p1++]);
		else if (res > 0)
			h.push_back(h2[p2++]);
		else
			if (sgn(cross(h1[p1].first - h2[p2].first, h2[p2].second - h2[p2].first)) < 0)
			{
				h.push_back(h1[p1++]);
				p2++;
			}
			else
			{
				h.push_back(h2[p2++]);
				p1++;
			}
	}
	while(p1 < h1.size()) 
		h.push_back(h1[p1++]);
	while(p2 < h2.size()) 
		h.push_back(h2[p2++]);

	deque<Halfplane> q;
	deque<Point> ans;
	q.push_back(h[0]);
	for (int i = 1; i < int(h.size()); ++i)
	{
		if (sgn(arg(h[i].second - h[i].first) - arg(h[i-1].second - h[i-1].first)) == 0)
			continue;
		while (ans.size() > 0 && !satisfy(ans.back(), h[i]))
		{
			ans.pop_back();
			q.pop_back();
		}
		while (ans.size() > 0 && !satisfy(ans.front(), h[i]))
		{
			ans.pop_front();
			q.pop_front();
		}
		ans.push_back(crosspoint(q.back(), h[i]));
		q.push_back(h[i]);
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
	Convex v1, v2;
	v1.push_back(Point(0,0));
	v1.push_back(Point(1,1));
	v1.push_back(Point(0,2));
	v1.push_back(Point(-1,1));
	v1.push_back(Point(-0.5,0));

	v2.push_back(Point(1,0));
	v2.push_back(Point(2,1));
	v2.push_back(Point(1,2));
	v2.push_back(Point(0,1));
	v2.push_back(Point(0.5,0));

	Convex v = convexIntersection(v1, v2);
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	return 0;
}