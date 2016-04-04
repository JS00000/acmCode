#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m;
	char a;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a;
			if (a=='.')
			{
				if ((i+j)%2==0)
					a='W';
				else
					a='B';
			}
			cout << a;
		}
		cout << '\n';
	}
	return 0;
}