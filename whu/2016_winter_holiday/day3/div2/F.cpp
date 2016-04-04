#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string str,ans;
	int n,m;
	cin >> n;
	cin >> ans;
	m = ans.length();
	for (int i = 1; i < n; ++i)
	{
		cin >> str;
		for (int i = 0; i < m; ++i)
		{
			if (str[i]==ans[i])
				continue;
			if (str[i]=='?')
				continue;
			if (ans[i]=='?')
				ans[i] = str[i];
			else ans[i] = '*';
		}
	}
	for (int i = 0; i < m; ++i)
	{
		if (ans[i]=='?')
			cout << 'x';
		else if (ans[i]=='*')
			cout << '?';
		else
			cout << ans[i];
	}
	cout << endl;
	return 0;
}