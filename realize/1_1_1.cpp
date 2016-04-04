// 矩阵类

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN=101;
const int MAXM=101;
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

int main(int argc, char const *argv[])
{
	Matrix a;
	a.n = 3;
	a.m = 5;
	Matrix b;
	b.n = 3;
	b.m = 5;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			a.a[i][j] = i+j;
			b.a[i][j] = i*j;
		}
	}
	a = a+b;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout << a.a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}