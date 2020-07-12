// Gauss消元

#include <iostream>
#include <cstdio>
#include <cmath>

#define EPS 0.0001

const int MAXN=101;
const int MAXM=101;

using namespace std;

inline int solve(double a[][MAXN], bool l[], double ans[], const int& n)
{
	int res = 0, r = 0;
	for (int i = 0; i < n; ++i)
		l[i] = false;
	for (int i = 0; i < n; ++i)
	{
		for (int j = r; j < n; ++j)
			if (fabs(a[j][i] > EPS))
			{
				for (int k = i; k <= n; ++k)
					swap(a[j][k], a[r][k]);
				break;
			}
		if (fabs(a[r][i]) < EPS)
		{
			++res;
			continue;
		}
		for (int j = 0; j < n; ++j)
			if (j!=r && fabs(a[j][i])>EPS)
			{
				double tmp = a[j][i] /a[r][i];
				for (int k = i; k <= n; ++k)
					a[j][k] -= tmp*a[r][k];
			}
		l[i] = true, ++r;
	}
	for (int i = 0; i < n; ++i)
		if (l[i])
			for (int j = 0; j < n; ++j)
				if (fabs(a[j][i])>0)
					ans[i] = a[j][n] / a[j][i];
	return res;
}

int main(int argc, char const *argv[])
{
	double a[3][MAXN];
	bool l[3];
	double ans[3];
	int n = 2;
	a[0][0] = 1; a[0][1] = 1; a[0][2] = 5;
	a[1][0] = 1; a[1][1] = 1; a[1][2] = 1;
	cout << solve(a, l, ans, n) << endl;
	for (int i = 0; i < 2; ++i)
	{
		if (l[i]) cout << ans[i] << " ";
		else cout << "x";
	}
	cout << endl;
	return 0;
}
