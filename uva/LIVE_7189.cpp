#include <cstdio>
#include <iostream>
#include <cmath>
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

int n;
point p[10];
int a[10];

void solve()
{
	int tx, ty;
	scanf("%d", &n);
	if (n != 4) 
	{
		for (int i = 0; i < n; ++i) scanf("%d%d", &tx, &ty);
		printf("NO\n");
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &tx, &ty);
			p[i] = point(tx, ty);
		}
		int k = 0;
		for (int i = 0; i < n-1; ++i)
			for (int j = i+1; j < n; ++j)
				a[k++] = (p[i]-p[j]).norm();
		sort(a, a+k);
		for (int i = 1; i < n; ++i)
			if (a[i] != a[0])
			{
				printf("NO\n");
				return;
			}
		printf("YES\n");
	}
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}