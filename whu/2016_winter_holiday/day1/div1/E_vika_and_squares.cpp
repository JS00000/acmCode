#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n,min,max,j,k;
	int c[400001];
	int f[400001]={0};
	long long sum=0;
	cin >> n;
	min = 1000000000001;
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
		c[i+n] = c[i];
		if (c[i]<min)
		{
			min = c[i];
			j = i;
		}
	}
	sum = min*n;
	if (c[0]>min)
	{
		f[0] = 1;
	}
	k = 1;
	while(k<n)
	{
		if (c[k]>min)
		{
			f[k] = f[k-1]+1;
		}
		k++;
	}
	if (f[n-1]!=n)
	{
		while(k<2*n)
		{
			if (c[k]>min)
			{
				f[k] = f[k-1]+1;
			}
			k++;
		}
	}
	max = 0;
	for (int i = 0; i < n*2; ++i)
	{
		if (f[i]>max)
		{
			max = f[i];
		}
	}
	cout << sum+max << endl;
	return 0;
}