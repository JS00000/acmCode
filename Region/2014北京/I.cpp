#include <cstdio>
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
	double norm()
	{
		return sqrt(x*x+y*y);
	}
	friend bool operator==(const point &a, const point &b)
	{
		return cmp(a.x-b.x) == 0 && cmp(a.y-b.y) == 0;
	}
	friend point operator+(const point &a, const point &b)
	{
		return point(a.x+b.x, a.y+b.y);
	}
	friend point operator-(const point &a, const point &b)
	{
		return point(a.x-b.x, a.y-b.y);
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
};

double det(const point &a, const point &b)
{
	return a.x*b.y-a.y*b.x;
}

point rotate(const point &p, double cost, double sint)
{
	double x = p.x, y = p.y;
	return point(x*cost - y*sint, x*sint + y*cost);
}

double crosspoint(point p, double ar, double br, double d)
{
	double costa = (ar*ar + d*d - br*br)/(2*ar*d);
	double costb = (br*br + d*d - ar*ar)/(2*br*d);
	double sinta = sqrt(1. - costa*costa);
	double sintb = sqrt(1. - costb*costb);
	point va = p / d * ar;
	point vb = -1 * p / d * br;
	return	(ar * ar * acos(costa) - 0.5 * det(rotate(va, costa, -sinta), rotate(va, costa, sinta))) + 
			(br * br * acos(costb) - 0.5 * det(rotate(vb, costb, -sintb), rotate(vb, costb, sintb)));
}

int main(int argc, char const *argv[])
{
	// freopen("input.txt", "r", stdin);
	int t, r, R, x1, x2, y1, y2, kase = 1;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d", &r, &R, &x1, &y1, &x2, &y2);
		point ap(x1, y1);
		point bp(x2, y2);
		if (ap == bp) printf("Case #%d: %.6lf\n", kase++, PI * (R * R - r * r));
		else
		{
			point p = bp - ap;
			double d = p.norm();
			double arr, arR, aRR;
			if (d >= 2 * r) arr = 0;
			else arr = crosspoint(p, r, r, d);
			if (d >= R + r) arR = 0;
			else if (d <= R - r) arR = PI * r * r;
			else arR = crosspoint(p, R, r, d);
			if (d >= 2 * R) aRR = 0;
			else aRR = crosspoint(p, R, R, d);
			// printf("%lf %lf %lf\n", aRR, arR, arr);
			printf("Case #%d: %.6lf\n", kase++, aRR - 2*arR + arr);
		}
	}
	return 0;
}