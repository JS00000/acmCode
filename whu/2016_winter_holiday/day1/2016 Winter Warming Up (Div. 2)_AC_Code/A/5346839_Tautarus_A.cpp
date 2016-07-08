#include<stdio.h>
int main(){
	int num[6],i=0,sub[3];
	while(i<6)
	{
		scanf("%d",&num[i]);
		i++;
	}
  i=0;
  while(i<3)
  {
  	sub[i]=num[i]-num[i+3];
  	if(sub[i]>0)
  		sub[i]=sub[i]/2;
  	i++;
  }
  if((sub[0]+sub[1]+sub[2])>=0)
  	printf("Yes");
  else
  	printf("No");
  return 0;
}