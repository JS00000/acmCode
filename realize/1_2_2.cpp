// 拓展欧几里得
// ax+by=gcd(a,b)
#include <iostream>

using namespace std;

int gcd_extend(int a, int b, int &x, int &y)
{
	if (b==0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int r = gcd_extend(b,a%b,y,x);
		y-=x*(a/b);
		return r;
	}
}

int main(int argc, char const *argv[])
{
	int x,y;
	gcd_extend(3,5,x,y);
	cout << x << " " << y << endl;
	cin.get();
	return 0;
}
