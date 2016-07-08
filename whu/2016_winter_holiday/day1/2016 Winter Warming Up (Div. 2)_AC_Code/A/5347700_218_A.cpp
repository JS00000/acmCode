#include <stdio.h>
int f(int a,int b)
{
	int k;
	if(a<=b)
	k=0; 
	if(a>b&&(a-b)%2==0)
	k=(a-b)/2;
	if(a>b&&(a-b)%2==1)
	k=(a-b)/2+1;
	return k;
}
int a[5],b[5];
int main()
{
	int i,n=0,t=0;
	for(i=1;i<=3;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=3;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=3;i++)
	{
	if(a[i]>b[i])
		n=n+f(a[i],b[i]);
	if(a[i]>=b[i]&&(a[i]-b[i])%2==1)
		t=t+1;
	if(a[i]<=b[i])
		t=t+(b[i]-a[i]);
	}
	if(n>=t)
	printf("Yes");
	if(n<t)
	printf("No");
	return 0;
}