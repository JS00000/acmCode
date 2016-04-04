#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	char s[100];
	unsigned long n,sum;
	bool p;
	while(~scanf("%s",s))
	{
		p = false;
		n = strlen(s);
		if (s[n-1]=='0'||s[n-1]=='2'||s[n-1]=='4'||s[n-1]=='5'||s[n-1]=='6'||s[n-1]=='8') p = true;
		sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum+= s[i]-'0';
		}
		if (sum%3==0) p = true;
		if (p)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
