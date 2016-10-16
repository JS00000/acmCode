// 圆与多边形交的面积
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
struct line
{
	point a,b;
	line(){}
	line(point x, point y) : a(x), b(y){}
};
bool parallel(const line &a,const line &b)
{
	return !cmp(det(a.a-a.b,b.a-b.b));
}
bool line_make_point(const line &a, const line &b, point &res)
{
	if (parallel(a,b)) return false;
	double s1=det(a.a-b.a,b.b-b.a);
	double s2=det(a.b-b.a,b.b-b.a);
	res = (s1*a.b-s2*a.a)/(s1-s2);
	return true;
}

vector<point> circle_cross_line(point a, point b, point o, double r)
{
	double dx = b.x - a.x, dy = b.y - a.y;
	double A = dx*dx + dy*dy;
	double B = 2*dx*(a.x-o.x) + 2*dy*(a.y-o.y);
	double C = (a.x-o.x)*(a.x-o.x) + (a.y-o.y)*(a.y-o.y) - r*r;
	double delta = B*B - 4*A*C;
	vector<point> ret;
	if (cmp(delta) > 0)
	{
		double t1 = (-B - sqrt(delta)) / (2*A);
		double t2 = (-B + sqrt(delta)) / (2*A);
		if (cmp(t1 - 1) <= 0 && cmp(t1) >= 0)
			ret.push_back(point(a.x+t1*dx, a.y+t1*dy));
		if (cmp(t2 - 1) <= 0 && cmp(t2) >= 0)
			ret.push_back(point(a.x+t2*dx, a.y+t2*dy));
	}
	else if (cmp(delta) == 0)
	{
		double t = -B / (2*A);
		ret.push_back(point(a.x+t*dx, a.y+t*dy));
	}
	return ret;
}

// 需要保证 pol[n] == pol[0]
point pol[maxn];
double r;
int n;

double mysqrt(double n)
{
	return sqrt(max(0.0, n));
}

double sector_area(const point &a, const point &b)
{
	double theta = atan2(a.y, a.x) - atan2(b.y, b.x);
	while(theta <= 0) theta += 2*PI;
	while(theta > 2*PI) theta -= 2*PI;
	theta = min(theta, 2*PI - theta);
	return r*r*theta/2;
}

double calc_part(const point &a, const point &b)
{
	if (cmp(dot(a, a) - r) < 0)
	{
		if (cmp(dot(b, b) - r) < 0)
			return fabs(det(a, b)) / 2.0;
		else
		{
			vector<point> p = circle_cross_line(a, b, point(0, 0), r);
			return sector_area(b, p[0]) + fabs(det(a, p[0])) / 2.0;
		}
	}
	else
	{
		if (cmp(dot(b, b) - r) < 0)
		{
			vector<point> p = circle_cross_line(a, b, point(0, 0), r);
			return sector_area(p[0], a) + fabs(det(p[0], b)) / 2.0;
		}
		else
		{
			vector<point> p = circle_cross_line(a, b, point(0, 0), r);
			if (p.size() == 2)
				return sector_area(a, p[0]) + sector_area(p[1], b) + fabs(det(p[0], p[1])) / 2.0;
			else
				return sector_area(a, b);
		}
	}
}
int main(int argc, char const *argv[])
{
	
	return 0;
}