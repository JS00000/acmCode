#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int cmp(int a, int b)
{
	return (abs(a)<abs(b));
}

int main(int argc, char const *argv[])
{

	int n,j;
	int a[50];
	bool b[50];
	cin >> n;
	cin >> a[0];
	int t = a[0];
	for (int i = 1; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	for (int i = 0; i < n; ++i)
	{
		if (t==a[i]) 
		{
			j = i;
			break;
		}
	}
	int sum = 0;
	if (a[j]>0)
	{
		for (int i = j+1; i < n; ++i)
		{
			if (a[i]<0) sum++;
		}
		if (sum!=0)
		{
			for (int i = 0; i < j; ++i)
			{
				if (a[i]>0) sum++;
			}
		}
		sum++;
	}
	else
	{
		for (int i = 0; i < j; ++i)
		{
			if (a[i]>0) sum++;
		}
		if (sum!=0)
		{
			for (int i = j+1; i < n; ++i)
			{
				if (a[i]<0) sum++;
			}
		}
		sum++;
	}
	cout << sum << endl;
	// cin >> n;
	return 0;
}
