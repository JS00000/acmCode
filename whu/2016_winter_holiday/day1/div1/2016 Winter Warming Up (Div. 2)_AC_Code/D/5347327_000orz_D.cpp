#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	if (n%2==1)
	{
		cout << "0\n";
	}
	else
	{
		n = n/2;
		if (n%2==1)
		{
			cout << n/2 << endl;
		}
		else
		{
			cout << n/2-1 << endl;
		}
	}
	return 0;
}