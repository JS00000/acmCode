#include <cstdio>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n,num;
int main()
{
	scanf("%d",&n);
	char s[500000],ss[500000],flag=0,fll=1;
	for (int i=0;i<n;i++)
	{
		scanf("%s",s);
		int l=strlen(s);
		if (s[0]=='0') {flag=1;break;}
		if (s[0]!='1') {strcpy(ss,s);continue;fll=0;}
		if (fll)
		{
			int numm=0;
			for (int j=0;j<l;j++) 
			{
				if (s[j]!='0') numm++;
				if (numm>1) break;
			}
			if (numm>1) {strcpy(ss,s);fll=0;continue;}
		}
		num+=l-1;
	}
	if (flag) printf("0");
	else 
	{
		if (strcmp(ss,"")!=0)	printf("%s",ss);
		else printf("1");
		for (int i=1;i<=num;i++) printf("0");
	}
	return 0;
}
