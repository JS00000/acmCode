#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,a[100001],d1,d2;
    scanf("%d\n",&n);
    for(d1=1;d1<=n;d1++)a[d1]=-1;
    for(d1=1;d1<=n;d1++) 
    { scanf("%d",&d2);
      a[d2]=d1; 
    }
    int s[100001],max;
    for(d1=1;d1<=n;d1++)s[d1]=1;
    max=1;
    for(d1=2;d1<=n;d1++)
    {if(a[d1]>a[d1-1]) s[d1]=s[d1-1]+1;
     if(s[d1]>max) max=s[d1];
    }
    printf("%d",n-max);
    return 0;
} 