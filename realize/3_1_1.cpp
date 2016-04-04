// 计算几何误差修正
#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-8;

int cmp(double x)
{
	if (fabs(x)<eps) return 0;
	if (x>0) return 1;
	return -1;
}

int main(int argc, char const *argv[])
{
	cout << cmp(0.00000000001) << endl;
	return 0;
}
