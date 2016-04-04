#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,t,now=1;
	int a[30001];
	int i = 0;
	cin >> n >> t;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> a[i];
	}
	while(1)
	{
		now+=a[i];
		if (now==t)
		{
			cout << "Yes\n";
			break;
		}
		if (now>t)
		{
			cout << "No\n";
			break;
		}
		i = i+a[i];
	}
	return 0;
}
