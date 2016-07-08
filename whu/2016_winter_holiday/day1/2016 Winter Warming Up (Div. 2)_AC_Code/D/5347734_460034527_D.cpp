#include<stdio.h>
#include<stdlib.h>
int main()
{
    long int n;
    scanf("%d",&n);
    if(n%2==0) n=(n/2+1)/2-1; else n=0;
    printf("%d",n);
    return 0;
}