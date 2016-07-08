#include<stdio.h>
void main()
{
	long a;
	scanf("%d",&a);
	if(a%2!=0)
		putchar('0');
	else
	{			
		a/=2;
		if(a%2==0)
			printf("%d\n",a/2-1);
		else
			printf("%d\n",a/2);
	}
} 