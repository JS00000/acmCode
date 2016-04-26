#include <cstdio>
#include <algorithm>
#include <cstring>


typedef long long LL;

using namespace std;

int main()
{
	LL t;
	scanf("%lld", &t);
	getchar();
	while(t--)
	{
		int cw,ce,cl,cc,co,cm;
		cw=ce=cl=cc=co=cm=0;
		char str[1001];
		fgets(str,1001,stdin);
		for (int i = 0; i < strlen(str); ++i)
		{
			if (str[i] == 'w')
				cw++;
			else if (str[i] == 'e')
				ce++;
			else if (str[i] == 'l')
				cl++;
			else if (str[i] == 'c')
				cc++;
			else if (str[i] == 'o')
				co++;
			else if (str[i] == 'm')
				cm++;
		}
		ce /= 2;
		int cmin = 10000;
		cmin = min(cmin, cw);
		cmin = min(cmin, ce);
		cmin = min(cmin, cl);
		cmin = min(cmin, cc);
		cmin = min(cmin, co);
		cmin = min(cmin, cm);
		printf("%d\n", cmin);
	}
	return 0;
}
