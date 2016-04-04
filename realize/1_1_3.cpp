// 矩阵的逆
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

inline vector<double> operator *(vector<double> a, double b)
{
	int N = a.size();
	vector<double> res(N,0);
	for (int i = 0; i < N; ++i)
		res[i] = a[i]*b;
	return res;
}
inline vector<double> operator -(vector<double> a, vector<double> b)
{
	int N = a.size();
	vector<double> res(N, 0);
	for (int i = 0; i < N; ++i)
		res[i] = a[i] - b[i];
	return res;
}
inline void inverse(vector<double> A[], vector<double> C[], int N)
{
	for (int i = 0; i < N; ++i)
		C[i] = vector<double>(N, 0);
	for (int i = 0; i < N; ++i)
		C[i][i] = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
			if (fabs(A[j][i]) > 0)
			{
				swap(A[i], A[j]);
				swap(C[i], C[j]);
				break;
			}
		C[i] = C[i] * (1/A[i][i]);
		A[i] = A[i] * (1/A[i][i]);
		for (int j = 0; j < N; ++j)
			if (j!=i && fabs(A[j][i])>0)
			{
				C[j] = C[j] - C[i] * A[j][i];
				A[j] = A[j] - A[i] * A[j][i];
			}
	}
}

int main(int argc, char const *argv[])
{
	vector<double> A[2];
	vector<double> C[2];
	A[0].push_back(1);
	A[0].push_back(2);
	A[1].push_back(3);
	A[1].push_back(4);
	inverse(A, C, 2);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}