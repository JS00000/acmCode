// 半平面切割多边形
#include <iostream>
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


struct polygon_convex
{
	vector<point> P;
	polygon_convex(int Size=0)
	{
		P.resize(Size);
	}
};

bool comp_less(const point &a, const point &b)
{
	return cmp(a.x-b.x)<0 || (cmp(a.x-b.x)==0 && cmp(a.y-b.y)<0);
}
polygon_convex convex_hull(vector<point> a)
{
	polygon_convex res(2*a.size()+5);
	sort(a.begin(),a.end(),comp_less);
	a.erase(unique(a.begin(),a.end()),a.end());
	int m=0;
	for (int i = 0; i < a.size(); ++i)
	{
		while(m>1 && cmp( det(res.P[m-1]-res.P[m-2], a[i]-res.P[m-2]) )<=0) --m;
		res.P[m++]=a[i];
	}
	int k=m;
	for (int i = int(a.size())-2; i >= 0; --i)
	{
		while(m>k && cmp( det(res.P[m-1]-res.P[m-2], a[i]-res.P[m-2]) )<=0) --m;
		res.P[m++]=a[i];
	}
	res.P.resize(m);
	if (a.size()>1) res.P.resize(m-1);
	return res;
}

bool containOn(const polygon_convex &a, const point &b)
{
	int n=a.P.size();
	#define next(i) ((i+1)%n)
	int sign=0;
	for (int i = 0; i < n; ++i)
	{
		int x=cmp( det(a.P[i]-b, a.P[next(i)]-b) );
		if (x)
		{
			if (sign)
			{
				if (sign!=x)
				{
					return false;
				}
			}
			else
			{
				sign=x;
			}
		}
	}
	return true;
}

// 返回1在内部，返回0在外部，返回-1在边界上
int containOlogn(const polygon_convex &a, const point &b)
{
	int n=a.P.size();
	point g=(a.P[0]+a.P[n/3]+a.P[n*2/3])/3.0;
	int l=0,r=n;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if (cmp(det(a.P[l]-g, a.P[mid]-g))>0 )
		{
			if (cmp(det(a.P[l]-g, b-g))>=0 && cmp(det(a.P[mid]-g, b-g))<0)
			{
				r=mid;
			}
			else
			{
				l=mid;
			}
		}
		else
		{
			if (cmp(det(a.P[l]-g, b-g))<0 && cmp(det(a.P[mid]-g, b-g))>=0)
			{
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
	}
	r%=n;
	int z=cmp(det(a.P[r]-b, a.P[l]-b))-1;
	if (z==-2) return 1;
	return z;
}

double convex_diameter(const polygon_convex &a, int &First, int &Second)
{
	const vector<point> &p=a.P;
	int n=p.size();
	double maxd=0.0;
	if (n==1)
	{
		First=Second=0;
		return maxd;
	}
	#define next(i) ((i+1)%n)
	for (int i=0,j=1; i < n; ++i)
	{
		while(cmp(det(p[next(i)]-p[i], p[j]-p[i]) - det(p[next(i)]-p[i], p[next(j)]-p[i]))<0)
		{
			j=next(j);
		}
		double d=dist(p[i], p[j]);
		if (d>maxd)
		{
			maxd = d;
			First = i;
			Second = j;
		}
		// 等等
		d = dist(p[next(i)], p[next(j)]);
		if (d>maxd)
		{
			maxd = d;
			First = i;
			Second = j;
		}
	}
	return maxd;
}

struct half_plane
{
	// ax+by+c<0
	double a,b,c;
	half_plane(point p, point q)
	{
		a = p.y-q.y;
		b = q.x-p.x;
		c = det(p,q);
	}
	half_plane(double aa, double bb, double cc)
	{
		a = aa;
		b = bb;
		c = cc;
	}
};


// 计算点a带入到直线方程中的函数值
double calc(const half_plane &L, const point &a)
{
	return a.x*L.a+a.y*L.b+L.c;
}

// 求过两点的直线与L边界的交点
point intersect(const point &a, const point &b, const half_plane &L)
{
	point res;
	double t1=calc(L,a), t2=calc(L,b);
	res.x=(t2*a.x-t1*b.x)/(t2-t1);
	res.y=(t2*a.y-t1*b.y)/(t2-t1);
	return res;
}

polygon_convex cut(const polygon_convex &a,const half_plane &L)
{
	int n=a.P.size();
	polygon_convex res;
	for (int i = 0; i < n; ++i)
	{
		if (cmp(calc(L, a.P[i]))<0) res.P.push_back(a.P[i]);
		else
		{
			int j=i-1;
			if (j<0) j=n-1;
			if (cmp(calc(L, a.P[j]))<0)
				res.P.push_back(intersect(a.P[j], a.P[i], L));
			j=i+1;
			if (j==n) j=0;
			if (cmp(calc(L, a.P[j]))<0)
				res.P.push_back(intersect(a.P[i], a.P[j], L));
		}
	}
	return res;
}


int main(int argc, char const *argv[])
{
	std::vector<point> ori;
	ori.push_back(point(1,0));
	ori.push_back(point(2,1));
	ori.push_back(point(3,0));
	ori.push_back(point(4,1));
	ori.push_back(point(3,2));
	ori.push_back(point(1,2));
	ori.push_back(point(0,1));
	polygon_convex res = convex_hull(ori);
	for (int i = 0; i < res.P.size(); ++i)
	{
		cout << res.P[i].x << " " << res.P[i].y << endl;
	}
	cout << endl;
	half_plane L(point(2,0), point(2,4));
	res = cut(res, L);
	for (int i = 0; i < res.P.size(); ++i)
	{
		cout << res.P[i].x << " " << res.P[i].y << endl;
	}
	return 0;
}
