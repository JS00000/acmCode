#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if( n%2 == 1)
	{
		cout << '0' << endl;
		return 0;
	}
	n = n >> 1;
	if( n%2 == 0)
		cout << n/2 - 1 << endl;
	else
		cout << (n - 1)/2 << endl;
	return 0;
}
