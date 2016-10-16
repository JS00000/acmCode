// 圆与线求交
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

int cmp(double x)
{
	if (fabs(x)<eps) return 0;
	if (x>0) return 1;
	return -1;
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
point rotate_point(const point &p, double A)
{
	double tx = p.x, ty = p.y;
	return point(tx*cos(A) - ty*sin(A), tx*sin(A) + ty*cos(A));
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

int main(int argc, char const *argv[])
{
	point a(1, -2);
	point b(0.99, 1);
	point o(0, 0);
	vector<point> cross = circle_cross_line(a, b, o, 1);
	for (std::vector<point>::iterator i = cross.begin(); i != cross.end(); ++i)
	{
		cout << i->x << " " << i->y << "\n";
	}
	return 0;
}