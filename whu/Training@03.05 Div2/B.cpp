#include <iostream>
#include <iomanip>

using namespace std;

double pow(double a, long b)
{
	double base = a;
	double r = 1;
	while(b!=0)
	{
		if (b&1) r=r*base;
		base=base*base;
		b>>=1;
	}
	return r;
}

int main(int argc, char const *argv[])
{
	/* code */
	int n,t;
	cin >> n >> t;
	cout << setprecision(20) << n*pow(1.000000011,t) << endl;
	return 0;
}
