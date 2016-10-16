// 最近点对
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100007;
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

point a[maxn];
int n, s[maxn];

bool cmpx(int i, int j)
{
	return cmp(a[i].x - a[j].x) < 0;
}

bool cmpy(int i, int j)
{
	return cmp(a[i].y - a[j].y) < 0;
}

double min_dist(point a[], int s[], int l, int r)
{
	double ans = 1e100;
	if (r - l < 20)
	{
		for (int q = l; q < r; q++)
			for (int w = q+1; w < r; w++) ans=min(ans, (a[s[q]]-a[s[w]]).norm());
		return ans;
	}
	int tl, tr, m=(l+r)/2;
	ans = min(min_dist(a, s, l, m), min_dist(a, s, m, r));
	for (tl = l; a[s[tl]].x < a[s[m]].x - ans; tl++);
	for (tr = r-1; a[s[tr]].x > a[s[m]].x + ans; tr--);
	sort(s+tl, s+tr, cmpy);
	for (int q=tl; q < tr; q++)
		for (int w=q+1; w<min(tr, q+6); w++)
			ans = min(ans, (a[s[q]] - a[s[w]]).norm());
	sort(s+tl, s+tr, cmpx);
	return ans;
}

double Min_Dist(point a[], int s[], int n)
{
	for (int i = 0; i < n; i++) s[i] = i;
	sort(s, s+n, cmpx);
	return min_dist(a, s, 0, n);
}

int main(int argc, char const *argv[])
{
	while(scanf("%d", &n), n != 0)
	{
		for (int i = 0; i < n; ++i)
			scanf("%lf%lf", &a[i].x, &a[i].y);
		printf("%.2f\n", Min_Dist(a, s, n) / 2);
	}
	return 0;
}
