#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
	int n,a,b;
	string op;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		cin >> op;
		cin >> b;
		if (op=="!=")
		{
			if (a!=b)
				cout << "true\n";
			else 
				cout << "false\n";
		}
		else if (op=="==")
		{
			if (a==b)
				cout << "true\n";
			else 
				cout << "false\n";
		}
		else if (op=="<")
		{
			if (a<b)
				cout << "true\n";
			else 
				cout << "false\n";
		}
		else if (op=="<=")
		{
			if (a<=b)
				cout << "true\n";
			else 
				cout << "false\n";
		}
		else if (op==">")
		{
			if (a>b)
				cout << "true\n";
			else 
				cout << "false\n";
		}
		else if (op==">=")
		{
			if (a>=b)
				cout << "true\n";
			else 
				cout << "false\n";
		}
	}
	return 0;
}