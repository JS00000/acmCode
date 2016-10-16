// 凸多边形与直线交
#include <iostream>
#include <cmath>
#include <complex>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

const double EPS 	= 1e-10;
const double PI		= acos(-1.0);
const double INF 	= 1e4;
const int maxn 	= 4096;

int cmp(double x)
{
	if (fabs(x)<EPS) return 0;
	if (x>0) return 1;
	return -1;
}

struct point
{
	double x,y;
	point(){}
	point(double a, double b) : x(a), y(b) {}
	friend point operator+(const point &a, const point &b){return point(a.x+b.x, a.y+b.y);}
	friend point operator-(const point &a, const point &b){return point(a.x-b.x, a.y-b.y);}
	friend bool operator==(const point &a, const point &b){return cmp(a.x-b.x) == 0 && cmp(a.y-b.y) == 0;}
	friend point operator*(const point &a, const double &b){return point(a.x*b, a.y*b);}
	friend point operator*(const double &a, const point &b){return point(a*b.x, a*b.y);}
	friend point operator/(const point &a, const double &b){return point(a.x/b, a.y/b);}
	double norm(){return sqrt(x*x+y*y);}
};
double det(const point &a, const point &b)
{
	return a.x*b.y-a.y*b.x;
}
double dot(const point &a, const point &b)
{
	return a.x*b.x+a.y*b.y;
}

inline bool operator < (const point &a, const point &b)
{
	return a.y+EPS<b.y || (fabs(a.y-b.y)<EPS && a.x+EPS<b.x);
}
inline double getA(const point &a)
{
	double res = atan2(a.y,a.x);
	if (res<0) res+=2*PI;
	return res;
}
point p[maxn], hull[maxn];
int n;
double w[maxn], sum[maxn];

inline void getHull()
{
	sort(p+1, p+n+1);
	int N = 0;
	hull[++N] = p[1];
	for (int i = 2; i <= n; ++i)
	{
		while(N>1 && det(hull[N]-hull[N-1], p[i]-hull[N-1]) <= 0) --N;
		hull[++N] = p[i];
	}
	int bak = N;
	for (int i = n-1; i >= 1; --i)
	{
		while(N>bak && det(hull[N]-hull[N-1], p[i]-hull[N-1]) <= 0) --N;
		hull[++N] = p[i];
	}
	n = N-1;
	for (int i = 1; i <= n; ++i)
		p[i+n] = p[i] = hull[i];
	p[n+n+1] = p[1];
	for (int i = 1; i <= n; ++i)
		w[i+n] = w[i] = getA(p[i+1]-p[i]);
	sum[0] = 0;
	for (int i = 1; i <= 2*n; ++i)
		sum[i] = sum[i-1]+det(p[i], p[i+1]);
}

inline int Find(double x)
{
	if (x <= w[1] || x >= w[n]) return 1;
	return (upper_bound(w+1, w+n+1, x) - (w+1)) + 1;
}

point P, Q;

inline int getInter(int l, int r)
{
	int sign;
	if (det(Q-P, p[1]-P)<0) sign=-1;
	else sign=1;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if (det(Q-P, p[mid]-P)*sign>0) l=mid;
		else r=mid;
	}
	return r;
}

inline point Intersect(const point &a, const point &b, const point &c, const point &d)
{
	double s1=det(c-a,b-a);
	double s2=det(d-a,b-a);
	return (c*s2-d*s1)/(s2-s1);
}

inline bool solve(point P, point Q)
{
	int i = Find(getA(Q-P));
	int j = Find(getA(P-Q));
	if (det(Q-P,p[i]-P)*det(Q-P, p[j]-P)>=0) return false;
	else return true;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
