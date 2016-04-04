#include <stdio.h>//D
#include <stdlib.h>

int main()
{
    long long int n,x;
    int i=0;
    scanf("%I64d",&n);
    x=n/2;
    if(n<=4||n%2!=0)
        printf("0\n");
    else
    {
        if(x%2!=0)
         printf("%I64d\n",(x-1)/2);
        else
         printf("%I64d\n",(x/2)-1);
    }

    return 0;
}
