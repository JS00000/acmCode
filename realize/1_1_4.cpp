// 常系数线性齐次递推
#include <iostream>
#include <cmath>

using namespace std;

const int MAXN=3;
const int MAXM=3;
struct Matrix
{
	int n,m;
	int a[MAXN][MAXM];
	void clear()
	{
		n=m=0;
		memset(a,0,sizeof(a));
	}
	Matrix operator +(const Matrix &b) const
	{
		Matrix tmp;
		tmp.n = n;
		tmp.m = m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				tmp.a[i][j] = a[i][j] + b.a[i][j];
		return tmp;
	}
	Matrix operator -(const Matrix &b) const
	{
		Matrix tmp;
		tmp.n = n;
		tmp.m = m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				tmp.a[i][j] = a[i][j] - b.a[i][j];
		return tmp;
	}
	Matrix operator *(const Matrix &b) const
	{
		Matrix tmp;
		tmp.clear();
		tmp.n = n;
		tmp.m = m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < b.m; ++j)
				for (int k = 0; k < m; ++k)
					tmp.a[i][j] += a[i][k]*b.a[k][j];
		return tmp;
	}
};

int solve(int a[], int b[], int n, int t)
{
	Matrix M,F,E;
	M.clear();
	F.clear();
	E.clear();
	M.n = M.m = n;
	E.n = E.m = n;
	F.n = n, F.m = 1;
	for (int i = 0; i < n-1; ++i)
		M.a[i][i+1] = 1;
	for (int i = 0; i < n; ++i)
	{
		M.a[n-1][i] = a[i];
		F.a[i][0] = b[i];
		E.a[i][i] = 1;
	}
	if (t<n)
		return F.a[t][0];
	for (t -= n-1; t; t/=2)
	{
		if (t&1)
			E = M*E;
		M = M*M;
	}
	F = E*F;
	return F.a[n-1][0];
}
int main(int argc, char const *argv[])
{
	// 系数
	int a[2] = {1,1};
	// 初值
	int b[2] = {0,1};
	for (int i = 0; i < 20; ++i)
		cout << solve(a, b, 2, i) << " ";
	return 0;
}
