#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,max;
	int num[100001];
	int f[100001] = {0};
	cin >> n;
	for (int i = 1; i < n+1; ++i)
	{
		cin >> num[i];
	}
	for (int i = 1; i < n+1; ++i)
	{
		f[num[i]] = f[num[i]-1]+1;
	}
	max = 0;
	for (int i = 1; i < n+1; ++i)
	{
		if (f[i]>max)
		{
			max = f[i];
		}
	}
	cout << n-max << endl;
	return 0;
}
