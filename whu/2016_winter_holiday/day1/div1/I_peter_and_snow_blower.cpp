#include <iostream>
#include <iomanip>
using namespace std;
const double PI=3.14159265358979323846264338327950288419;
int main(int argc, char const *argv[])
{
	int n,x0,y0,x,y;
	long long len2;
	double max,min;
	cin >> n >> x0 >> y0;
	max = 0;
	min = 10000000000000000;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		len2 = ((x-x0)*(x-x0))+((y-y0)*(y-y0));
		if (max<len2)
		{
			max = len2;
		}
		if (min>len2)
		{
			min = len2;
		}
	}
	cout << fixed << setprecision(20)<<PI*(max-min)<<endl;
	return 0;
}