#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>

using namespace std;

int mod, c;

struct Matrix
{
	int n,m;
	int a[3][3];
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
				tmp.a[i][j] = (a[i][j] - b.a[i][j]) % mod;
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
					tmp.a[i][j] = (tmp.a[i][j] + (a[i][k] * b.a[k][j]) % mod) % mod;
		return tmp;
	}
};

int solve(int x, long long t)
{
	Matrix M,F,E;
	M.clear();
	F.clear();
	E.clear();
	M.n = M.m = 2;
	E.n = E.m = 2;
	F.n = 2, F.m = 1;
	M.a[0][0] = 1;
	M.a[0][1] = 0;
	M.a[1][0] = x;
	M.a[1][1] = 10;

	E.a[0][0] = 1;
	E.a[1][1] = 1;

	F.a[0][0] = 1;
	F.a[1][0] = x;
	if (t<2)
		return F.a[t][0];
	for (t -= 1; t; t/=2)
	{
		if (t&1)
			E = M*E;
		M = M*M;
	}
	F = E*F;
	return F.a[1][0];
}

int main()
{
	int t, x, kase = 0;
	long long m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %lld %d %d", &x, &m, &mod, &c);
		printf("Case #%d:\n", ++kase);
		if (solve(x, m) != c) puts("No");
		else puts("Yes");

	}
	return 0;
}
