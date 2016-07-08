#include<stdio.h>
#include<stdlib.h>
int main()
{
    long int a,b,c,x,y,z;
    scanf("%d %d %d\n",&a,&b,&c);
    scanf("%d %d %d",&x,&y,&z);
    long int zheng,fu,d1;
    zheng=0; fu=0;
    if(a>x) zheng=zheng+(a-x)/2; else fu=fu+(a-x);
    if(b>y) zheng=zheng+(b-y)/2; else fu=fu+(b-y);
    if(c>z) zheng=zheng+(c-z)/2; else fu=fu+(c-z);
    if(zheng+fu>=0)printf("YES");else printf("NO");
    return 0;
} 