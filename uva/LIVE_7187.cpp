#include <cstdio>
#include <iostream>
#include <cmath>

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

int n;
double a[20007];
double r[20007];

void check(double r0)
{
	if (cmp(r0) < 0)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	r[0] = r0;
	double s = r0*r0;
	for (int i = 1; i < n; ++i)
	{
		r[i] = a[i] - r[i-1];
		s += r[i] * r[i];
		if (cmp(r[i]) < 0)
		{
			printf("IMPOSSIBLE\n");
			return;
		}
	}
	printf("%.2f\n", s*PI);
	for (int i = 0; i < n; ++i)
		printf("%.2f\n", r[i]);
	return;
}

void solve()
{
	double y = 0.;
	double L = 0., R = a[1];
	for (int i = 1; i <= n; ++i)
	{
		if (i & 1) 
		{
			y += a[i];
			R = min(R, y);
		}
		else
		{
			y -= a[i];
			L = max(L, y);
		}
		if (cmp(L-R)>0)
		{
			printf("IMPOSSIBLE\n");
			return;
		}
	}
	if (cmp(y) != 0)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	for (int i = 1; i < n; ++i)
		if (i & 1) y += a[i] * (n-i) * 2;
		else y -= a[i] * (n-i) * 2;
	y = y/n/2;
	if (L > y) check(L);
	else if (R < y) check(R);
	else check(y);
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		point t0, t1, t2;
		int tx, ty;
		scanf("%d%d", &tx, &ty);
		t1 = point(tx, ty);
		t0 = t1;
		for (int i = 1; i < n; ++i)
		{
			scanf("%d%d", &tx, &ty);
			t2 = point(tx, ty);
			a[i] = (t2-t1).norm();
			t1 = t2;
		}
		a[n] = (t0-t2).norm();
		if (n & 1)
		{
			double y = 0.;
			for (int i = 1; i <= n; ++i)
				if (i & 1) y += a[i];
				else y -= a[i];
			check(y/2);
		}
		else
		{
			solve();
		}
	}
	return 0;
}