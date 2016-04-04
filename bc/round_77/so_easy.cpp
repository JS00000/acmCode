#include <iostream>

#define MAXN 1001

using namespace std;

int a[MAXN] = {0};

int main(int argc, char const *argv[])
{
	int T,n;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		if (n==1)
		{
			cout << a[0] << endl;
		}
		else
		{
			cout << "0" << endl;
		}
	}
	return 0;
}
