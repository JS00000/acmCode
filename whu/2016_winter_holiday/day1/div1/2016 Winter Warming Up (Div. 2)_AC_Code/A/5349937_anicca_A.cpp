#include<stdio.h>
int main()
{
    int a,b,c,x,y,z;
    long long m,n;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z);
    m=n=0;
    int p,q,r;
    p=q=r=0;
    if(a-x>=0) p=0,n+=(a-x)/2;
    else p=a-x;
    if(b-y>=0) q=0,n+=(b-y)/2;
    else q=b-y;
    if(c-z>=0) r=0,n+=(c-z)/2;
    else r=c-z;
    if(n+p+q+r>=0) printf("Yes\n");
    else printf("No\n");
    
    return 0;
}