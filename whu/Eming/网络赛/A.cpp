#include <iostream>
#include <cstdio>
#include <math.h>
#include <iomanip>


#define PI 3.14159265

using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	int n;
	int a,b,c,d,e,x,y;
	double m[2][2];
	double dx,dy;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c >> d >> e;
		x = a-c;
		y = b-d;
		m[0][0] = cos(e*PI/180);
		m[0][1] = -sin(e*PI/180);
		m[1][0] = sin(e*PI/180);
		m[1][1] = cos(e*PI/180);
		dx = m[0][0]*x + m[0][1]*y;
		dy = m[1][0]*x + m[1][1]*y;
		printf("%.3lf %.3lf\n", c+dx, d+dy);
	}
	return 0;
}
