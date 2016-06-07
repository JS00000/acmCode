// 中国剩余定理

#include <iostream>
#include <vector>
#define LL long long

using namespace std;


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
	int n = 3;
	int a[9] = {1, 0, 4};
	int m[9] = {2, 3, 5};
	cout << crt(a,m,n) << endl;
	return 0;
}
