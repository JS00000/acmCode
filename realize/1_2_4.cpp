// 中国剩余定理

#include <iostream>
#include <vector>
#define LL long long

using namespace std;

int n;
int a[10],m[10];

LL gcd_extend(LL a, LL b, LL &x, LL &y)
{
	if (b==0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		LL r = gcd_extend(b,a%b,y,x);
		y-=x*(a/b);
		return r;
	}
}

int crt(int a[],int m[], int n)
{
	LL M = 1;
	for (int i = 0; i < n; ++i)
	{
		M *= m[i];
	}
	LL ret = 0;
	for (int i = 0; i < n; ++i)
	{
		LL x,y;
		LL tm = M/m[i];
		gcd_extend(tm,m[i],x,y);
		ret = (ret+tm*x*a[i])%M;
	}
	return (ret+M)%M;
}


int main(int argc, char const *argv[])
{
	n = 3;
	a[0] = 3;
	a[1] = 1;
	a[2] = 2;
	m[0] = 5;
	m[1] = 7;
	m[2] = 11;
	cout << crt(a,m,n) << endl;
	cin.get();
	return 0;
}
