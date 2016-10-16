// 圆与圆求交
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1007;
const double eps = 1e-8;
const double PI = acos(-1.0);

int cmp(double x)
{
	return x < -eps ? -1 : x > eps ? 1 : 0;
}

struct point
{
	double x,y;
	point(){}
	point(double a, double b) : x(a), y(b) {}
	friend point operator+(const point &a, const point &b)
	{
		return point(a.x+b.x, a.y+b.y);
	}
	friend point operator-(const point &a, const point &b)
	{
		return point(a.x-b.x, a.y-b.y);
	}
	friend bool operator==(const point &a, const point &b)
	{
		return cmp(a.x-b.x) == 0 && cmp(a.y-b.y) == 0;
	}
	friend point operator*(const point &a, const double &b)
	{
		return point(a.x*b, a.y*b);
	}
	friend point operator*(const double &a, const point &b)
	{
		return point(a*b.x, a*b.y);
	}
	friend point operator/(const point &a, const double &b)
	{
		return point(a.x/b, a.y/b);
	}
	double norm()
	{
		return sqrt(x*x+y*y);
	}
};
double det(const point &a, const point &b)
{
	return a.x*b.y-a.y*b.x;
}
double dot(const point &a, const point &b)
{
	return a.x*b.x+a.y*b.y;
}
double dist(const point &a, const point &b)
{
	return (a - b).norm();
}

point rotate(const point &p, double cost, double sint)
{
	return point(p.x*cost - p.y*sint, p.x*sint + p.y*cost);
}

pair<point, point> cross_point(point ap, double ar, point bp, double br)
{
	double d = (ap - bp).norm();
	double cost = (ar*ar + d*d - br*br) / (2*ar*d);
	double sint = sqrt(1. - cost*cost);
	point v = (bp - ap) / (bp - ap).norm() * ar;
	return make_pair(ap+rotate(v, cost, -sint), ap+rotate(v, cost, sint));
}

int main(int argc, char const *argv[])
{
	pair<point, point> ans;
	ans = cross_point(point(0, 0), 2, point(2, 0), 2);
	cout << ans.first.x << " " << ans.first.y << " " << ans.second.x << " " << ans.second.y << endl;
	return 0;
}
