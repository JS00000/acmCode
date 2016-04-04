#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m;
	char a[101][101];
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
			if (a[i][j]=='.')
			{
				if ((i+j)%2==0)
					a[i][j]='W';
				else
					a[i][j]='B';
			}
			cout << a[i][j];
		}
		cout << '\n';
	}
	return 0;
}