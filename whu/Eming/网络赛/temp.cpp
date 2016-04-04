#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	string str = "asdf";
	cout << str.length() << endl;
	cout << str.substr(2,10) << "hehe" << endl;
	int n,N;
	n = 1;
	N = 2;
	// cout << n << N;
	n = 4;
	while(n-=2)
	{
		cout << n << endl;
	}
	bool a = 0;
	a ^= 1;
	cout << a << endl;
	a ^= 1;
	cout << a << endl;
	a ^= 1;
	cout << a << endl;
	a ^= 1;
	cout << a << endl;
	return 0;
}