#include <iostream>
#include <algorithm>
#include <complex>

using namespace std;

typedef complex<double> Point;
int main(int argc, char const *argv[])
{
	Point a(1,0);
	Point b(10,1);
	cout << a/b << endl;
	return 0;
}