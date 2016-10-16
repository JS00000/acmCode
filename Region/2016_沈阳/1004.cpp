#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int f[100];
int a[100];

int main(int argc, char const *argv[])
{
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < 20; ++i)
	{
		f[i] = f[i-2] + 2*f[i-1];
		printf("%d:	%d\n", i, f[i]);
	}
	for (int i = 0; i < 20; ++i)
	{
		a[i] = sqrt(2)/4*()
	}
	return 0;
}