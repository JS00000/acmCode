#include <stdio.h>
int main()
{
	int i,k; 
	scanf("%d",&i);
	if(i%2==0&&(i/2)%2==0)
		k=i/4-1;
	if(i%2==1)
		k=0;
	if(i%2==0&&(i/2)%2==1)
		k=(i/2)/2;
	printf("%d",k);
	return 0;
}