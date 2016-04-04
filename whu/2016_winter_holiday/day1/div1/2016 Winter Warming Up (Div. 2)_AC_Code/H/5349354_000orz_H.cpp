#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,t,zores=0,k=-1;
	bool p;
	string a[100001];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i][0]=='0'&&a[i].length()==1)
		{
			cout << "0\n";
			return 0;
		}
		p = true;
		t = 0;
		for (int j = 0; j < a[i].length(); ++j)
		{
			if (!(a[i][j]=='1'||a[i][j]=='0'))
			{
				p = false;
			}
			if (a[i][j]=='1')
			{
				t++;
			}
		}
		if (!p||t>1)
		{
			k = i;
		}
		else
		{
			zores+=a[i].length()-1;
		}
	}
	if (k==-1)
	{
		cout << '1';
	}
	else
	{
		cout << a[k];
	}
	for (int i = 0; i < zores; ++i)
	{
		cout << '0';
	}
	cout << endl;
	return 0;
}