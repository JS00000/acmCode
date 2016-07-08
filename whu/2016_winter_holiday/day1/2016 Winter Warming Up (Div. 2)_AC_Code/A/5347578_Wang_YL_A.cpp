#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b,c,x,y,z,difference1,difference2,difference3;	
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d %d %d",&x,&y,&z);
	
	if(a>=x)
	difference1=(a-x)/2;
	else
	difference1=a-x;
	if(b>=y)
	difference2=(b-y)/2;
	else
	difference2=b-y;
	if(c>=z)
	difference3=(c-z)/2;
	else
	difference3=c-z;
	
	if(difference1+difference2+difference3<0)
	printf("No");
	else
	printf("Yes");
	
}
		