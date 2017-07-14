#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);

int main()
{
	int T;
	scanf("%d", &T);
	double d, eps = 1e-9;
	while(T--)
	{
		scanf("%lf", &d);
		if (fabs(d) < eps) printf("0.00000\n");
		else if (d >= 2.) printf("3.14159\n");
		else if (d >= 1.) printf("%.5f\n", pi*sqrt(d*d-4*d+5));
		else
		{
			double l = 0, r = pi+eps, mid;
			while(r-l>eps)
			{
				mid = (l+r)/2;
				double error = pi*d*(1-cos(mid)) - 2*(sin(mid) - mid*cos(mid) - sin(mid)*sin(mid)*sin(mid)/3);
				if (fabs(error) < eps) break;
				else if (error < 0) r = mid;
				else l = mid;
			}
			printf("%.5f\n", (mid - sin(mid)*cos(mid)) / cos(atan2(2, 1-(cos(mid)))));
		}
	}
	return 0;
}
