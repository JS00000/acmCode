#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	int m,l,r,k;
	int s[10001];
	int temp[10001];
	cin >> str;
	for (int i = 0; i <= str.length(); ++i)
	{
		s[i] = i;
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> l >> r >> k;
		k = k%(r-l+1);
		for (int j = l; j < l+k; ++j)
		{
			temp[j] = s[j+r-l+1-k];
		}
		for (int j = l+k; j <= r; ++j)
		{
			temp[j] = s[j-k];
		}
		for (int j = l; j <= r; ++j)
		{
			s[j] = temp[j];
		}
	}
	for (int i = 0; i < str.length(); ++i)
	{
		cout << str[s[i+1]-1];
	}
	cout << endl;
	return 0;
}