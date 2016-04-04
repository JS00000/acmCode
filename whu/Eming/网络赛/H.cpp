#include <iostream>
#include <cstdio>

using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	int n,s,t;
	while(~scanf("%d%d%d",&n,&s,&t))
	{
		if (n==1)
		{
			cout << "0\n";
			continue;
		}
		if (s==t)
		{
			cout << "-1\n";
			continue;
		}
		if ((s==1&&t==n)||(s==n&&t==1))
		{
			cout << "0\n";
			continue;
		}
		if (s==t-1||s==t+1||s==1||s==n)
		{
			cout << "1\n";
			continue;
		}
		cout << "2\n";
		continue;
	}
	return 0;
}
