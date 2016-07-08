#include<stdio.h>
int main(){
	int n,i,j,m;
	scanf("%d",&n);
	if(n%2==0)
	{
		if(n%4==0)
		    printf("%d",n/4-1);
		else
		    printf("%d",n/4);
	}
	else
	    printf("0");
	
  return 0;
}