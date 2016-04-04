#include <iostream>
#include <algorithm>
#include <cstdio>

bool cmp(int a, int b)
{
	return (a>b);
}

using namespace std;
int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	while(T)
	{
		int n,m,k;
		int a[101];
		long sum = 0;
		cin >> k >> m >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			sum += a[i];
		}
		sort(a,a+n,cmp);
		int j = 0;
		while(sum>k-m)
		{
			sum -= a[j];
			j++;
		}

		cout << j << endl;
		T--;
	}
	return 0;
}