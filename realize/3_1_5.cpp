// 多边形的重心
#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 100;

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
struct line
{
	point a,b;
	line(){}
	line(point x, point y) : a(x), b(y){}
};
double dis_point_segment(const point &p, const point &s, const point &t)
{
	if (cmp(dot(p-s,t-s))<0) return (p-s).norm();
	if (cmp(dot(p-t,s-t))<0) return (p-t).norm();
	return fabs(det(s-p,t-p)/dist(s,t));
}
void point_proj_line(const point &p, const point &s, const point &t, point &cp)
{
	double r=dot((t-s),(p-s)/dot(t-s,t-s));
	cp=s+r*(t-s);
}
bool point_on_segment(const point &p, const point &s, const point &t)
{
	return cmp(det(p-s,t-s))==0 && cmp(dot(p-s,p-t))<=0;
}
bool parallel(const line &a,const line &b)
{
	return !cmp(det(a.a-a.b,b.a-b.b));
}
bool line_make_point(const line &a, const line &b, point &res)
{
	if (parallel(a,b)) return false;
	double s1=det(a.a-b.a,b.b-b.a);
	double s2=det(a.b-b.a,b.b-b.a);
	cout << s1 << " " << s2 << endl;
	res = (s1*a.b-s2*a.a)/(s1-s2);
	return true;
}
line move_d(const line &a, const double &len)
{
	point d=a.b-a.a;
	d=d/d.norm();
	d=rotate_point(d,PI/2);
	return line(a.a+d*len, a.b+d*len);
}
struct polygon
{
	int n;
	point a[maxn];
	polygon(){}
	double perimeter()
	{
		double sum=0;
		a[n] = a[0];
		for (int i = 0; i < n; ++i)
			sum+=(a[i+1]-a[i]).norm();
		return sum;
	}
	double area()
	{
		double sum = 0;
		a[n] = a[0];
		for (int i = 0; i < n; ++i) sum+=det(a[i+1],a[i]);
		return sum/2;
	}
	int point_in(point t)
	{
		int num=0,i,d1,d2,k;
		a[n] = a[0];
		for (int i = 0; i < n; ++i)
		{
			if (point_on_segment(t,a[i],a[i+1])) return 2;
			k = cmp(det(a[i+1]-a[i],t-a[i]));
			d1= cmp(a[i].y-t.y);
			d2= cmp(a[i+1].y-t.y);
			if (k>0 && d1<=0 && d2>0) num++;
			if (k<0 && d2<=0 && d1>0) num--;
		}
		return num!=0;
	}
	point mass_center()
	{
		point ans(0,0);
		if (cmp(area())==0) return ans;
		a[n] = a[0];
		for (int i = 0; i < n; ++i) ans=ans+(a[i]+a[i+1])*det(a[i+1],a[i]);
		return ans/area()/6.;
	}
};



int main(int argc, char const *argv[])
{
	point a(1,0);
	point b(3,1);
	point c(1,2);
	point d(0,1);
	polygon pol;
	pol.a[0] = a;
	pol.a[1] = b;
	pol.a[2] = c;
	pol.a[3] = d;
	pol.n = 4;
	point t(1,1);
	cout << pol.point_in(t) << endl;
	t = pol.mass_center();
	cout << t.x << " " << t.y << endl;
	return 0;
}
