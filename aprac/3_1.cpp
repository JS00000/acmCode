#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double eps=1e-8;

int cmp(double x)
{
	if (fabs(x)<eps) return 0;
	if (x>0) return 1;
	return -1;
}

struct point
{
	double x,y;
	point(){};
	point(double a, double b) : x(a), y(b) {}
	void input()
	{
		scanf("%lf%lf", &x, &y);
	}
	friend point operator+(const point &a, const point &b)
	{
		return point(a.x+b.x, a.y+b.y);
	}
	friend point operator-(const point &a, const point &b)
	{
		return point(a.x-b.x, a.y-b.y);
	}
};
double det(const point &a, const point &b)
{
	return a.x*b.y-a.y*b.x;
}


double cross(const point &a, const point &b, const point &c)
{
	return det(point(b.x-a.x, b.y-a.y), point(c.x-a.x, c.y-a.y));
}

struct line
{
	point a,b;
	line(){}
	line(point x, point y) : a(x), b(y) {}
};

int xyCmp(const double p, const double mini, const double maxi)
{
	return cmp(p-mini)*cmp(p-maxi);
}
int betweenCmp(const point &a, const point &b, const point &c)
{
	if (fabs(b.x-c.x)>fabs(b.y-c.y))
		return xyCmp(a.x, min(b.x,c.x), max(b.x,c.x));
	else
		return xyCmp(a.y, min(b.y,c.y), max(b.y,c.y));
}

int segCross(const line &l, const line &m)
{
	double s1,s2,s3,s4;
	int d1,d2,d3,d4;
	d1 = cmp(s1=cross(l.a,l.b,m.a));
	d2 = cmp(s2=cross(l.a,l.b,m.b));
	d3 = cmp(s3=cross(m.a,m.b,l.a));
	d4 = cmp(s4=cross(m.a,m.b,l.b));
	if ((d1^d2)==-2 && ((d3^d4)==-2))
		return 1;
	if ((d1==0 && betweenCmp(m.a, l.a, l.b)<=0)||
		(d2==0 && betweenCmp(m.b, l.a, l.b)<=0)||
		(d3==0 && betweenCmp(l.a, m.a, m.b)<=0)||
		(d4==0 && betweenCmp(l.b, m.a, m.b)<=0))
		return 2;
	return 0;
}


int main(int argc, char const *argv[])
{
	line l1(point(0,0), point(2,2));
	line l2(point(0,1), point(1,1));
	printf("%d\n", segCross(l1,l2));
	return 0;
}
