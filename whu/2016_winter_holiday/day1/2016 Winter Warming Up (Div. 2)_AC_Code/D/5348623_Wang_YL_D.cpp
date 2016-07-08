#include<stdio.h>
#include<stdlib.h>

int main()
{
	int length,x,y;
	scanf("%d",&length);
	if(length%2==1)
	   {printf("0");}
	else
	  {
	   x=length/2; 
       if(x%2==1)
       {
	   y=x/2;}
       else
       {
	   y=x/2-1;}
	   printf("%d",y);}
}