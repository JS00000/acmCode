#include "iostream"
#include "ctime"

using namespace std;

long pow(long a, long b, long n);

int main(int argc, char const *argv[])
{
	/* code */
	clock_t start, finish;
	start = clock();
	
	cout << pow(26, 11, 1000000007);

	// long r = 1;
	// for (int i = 0; i < 10000; ++i)
	// {
	// 	r = r*2%1000000;
	// }
	// cout << r;

	finish = clock();
	cout << "\nTime:" << double(finish - start) << endl;
	return 0;
}

long pow(long a, long b, long n)
{
	long base = a;
	long r = 1;
	while(b!=0)
	{
		if (b&1) r=r*base%n;
		base=base*base%n;
		b>>=1;
	}
	return r;
}