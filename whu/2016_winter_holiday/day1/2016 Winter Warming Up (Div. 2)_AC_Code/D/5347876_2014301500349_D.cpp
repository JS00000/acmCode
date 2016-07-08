#include<iostream>
#include<cstdio>
#include<stack>
#include<string>

using namespace std;
int main()
{
	long long number = 0;
	long long n;
	scanf("%lld", &n);
	if (n % 2 == 1)
		cout << 0;
	else
	{
		number = n / 2 - n / 4 - 1;
		printf("%lld", number);
	}
	return 0;
}