// 常系数线性齐次递推
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long LL;
const LL mod = 2147493647;
const int MAXN=7;
const int MAXM=7;
struct Matrix
{
	int n,m;
	LL a[MAXN][MAXM];
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
				tmp.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
		return tmp;
	}
	Matrix operator -(const Matrix &b) const
	{
		Matrix tmp;
		tmp.n = n;
		tmp.m = m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				tmp.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
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
					tmp.a[i][j] = (tmp.a[i][j] + (a[i][k]*b.a[k][j] % mod) % mod) % mod;
		return tmp;
	}
};

// a[]矩阵, b[]初始值
LL solve(int b[], int n, int t)
{
	if (t == 0) return b[0];
	if (t == 1) return b[1];
	Matrix M,F,E;
	M.clear();
	F.clear();
	E.clear();
	M.n = M.m = n;
	E.n = E.m = n;
	F.n = n, F.m = 1;

	F.a[0][0] = b[1] % mod;
	F.a[1][0] = b[0] % mod;
	F.a[2][0] = 81;
	F.a[3][0] = 27;
	F.a[4][0] = 9;
	F.a[5][0] = 3;
	F.a[6][0] = 1;

	M.a[0][0] = 1;
	M.a[0][1] = 2;
	M.a[0][2] = 1;
	M.a[1][0] = 1;
	M.a[2][2] = 1;
	M.a[2][3] = 4;
	M.a[2][4] = 6;
	M.a[2][5] = 4;
	M.a[2][6] = 1;
	M.a[3][3] = 1;
	M.a[3][4] = 3;
	M.a[3][5] = 3;
	M.a[3][6] = 1;
	M.a[4][4] = 1;
	M.a[4][5] = 2;
	M.a[4][6] = 1;
	M.a[5][5] = 1;
	M.a[5][6] = 1;
	M.a[6][6] = 1;
	for (int i = 0; i < n; ++i)
		E.a[i][i] = 1;
	for (t = t-1; t; t/=2)
	{
		if (t&1)
			E = M*E;
		M = M*M;
	}
	F = E*F;
	return (F.a[0][0] % mod + mod) % mod;
}
int main(int argc, char const *argv[])
{
	int T, m;
	int b[2];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &m, b, b+1);
		cout << solve(b, 7, m-1) << endl;
	}
	return 0;
}
