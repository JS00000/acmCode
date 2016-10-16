// 最小圆覆盖 hdu3007
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

// 三角形外心
void circle_center(point p0, point p1, point p2, point &cp)
{
	double a1 = p1.x - p0.x, b1 = p1.y - p0.y, c1 = (a1*a1 + b1*b1) / 2;
	double a2 = p2.x - p0.x, b2 = p2.y - p0.y, c2 = (a2*a2 + b2*b2) / 2;
	double d = a1*b2 - a2*b1;
	cp.x = p0.x + (c1*b2 - c2*b1) / d;
	cp.y = p0.y + (a1*c2 - a2*c1) / d;
}
void circle_center(point p0, point p1, point &cp)
{
	cp.x = (p0.x+p1.x)/2;
	cp.y = (p0.y+p1.y)/2;
}

point center;
double radius;
point a[maxn];
int n;

bool point_in(const point &p)
{
	return cmp((p - center).norm() - radius) < 0;
}

void min_circle_cover(point a[], int n)
{
	radius = 0;
	center = a[0];
	for (int i = 1; i < n; ++i) if (!point_in(a[i]))
	{
		radius = 0;
		center = a[0];
		for (int j = 0; j < i; ++j) if (!point_in(a[j]))
		{
			circle_center(a[i], a[j], center);
			radius = (a[j] - center).norm();
			for (int k = 0; k < j; ++k) if (!point_in(a[k]))
			{
				circle_center(a[i], a[j], a[k], center);
				radius = (a[k] - center).norm();
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	while(n)
	{
		double t1, t2;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf%lf", &t1, &t2);
			a[i] = point(t1, t2);
		}
		random_shuffle(a, a + n);
		min_circle_cover(a, n);
		printf("%.2lf %.2lf %.2lf\n", center.x, center.y, radius);
		scanf("%d", &n);
	}
	return 0;
}
