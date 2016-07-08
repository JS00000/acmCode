#include<cstdio>
#include<iostream>

using namespace std;
int a[210000],b[210000];

int main()
{
	long long n,min = 1000000000,bn = 1;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] < min)
		{
			min = a[i];
			bn = 1;
			b[bn++] = i;

		}
		if(a[i] == min)
			b[bn++] = i;
	}
	b[0] = n - (b[bn-1] - b[1]) - 1;
	long long max = b[0];
	for(int i = 1; i < bn - 1; i++)
	{
		b[i] = b[i+1] - b[i] - 1;
		if(b[i] > max)
			max = b[i];
	}
	cout << n*min + max << endl;
	
	return 0;
}
