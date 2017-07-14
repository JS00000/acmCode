// 自适应Simpson公式 求函数定积分
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);

// 函数F
double F(double x)
{
	return (x - sin(x)*cos(x))*sin(x);
}
// 三点Simpson法
double simpson(double a, double b)
{
	double c = a + (b-a)/2;
	return (F(a) + 4*F(c) + F(b))*(b-a)/6;
}

// 自适应Simpson公式(递归过程)
double asr(double a, double b, double eps, double A)
{
	double c = a + (b-a)/2;
	double L = simpson(a, c), R = simpson(c, b);
	if (fabs(L+R-A) <= 15*eps) return L+R+(L+R-A)/15.0;
	return asr(a, c, eps/2, L) + asr(c, b, eps/2, R);
}

// 自适应Simpson公式(主过程)
double asr(double a, double b, double eps)
{
	return asr(a, b, eps, simpson(a, b));
}

int main()
{
	printf("%f\n", asr(0, pi, 1e-9));
	return 0;
}
