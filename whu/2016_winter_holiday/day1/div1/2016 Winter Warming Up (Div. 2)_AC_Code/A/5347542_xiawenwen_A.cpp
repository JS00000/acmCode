#include<stdio.h>
int main()
{
    long long a,b,c,x,y,z,ans=0;
    scanf("%lld%lld%lld",&a,&b,&c);
    scanf("%lld%lld%lld",&x,&y,&z);
    a=a-x;
    b=b-y;
    c=c-z;
    if(a>0)ans+=a/2;
    else ans+=a;
    if(b>0)ans+=b/2;
    else ans+=b;
    if(c>0)ans+=c/2;
    else ans+=c;
    if(ans>=0)printf("Yes");
    else printf("No");
    return 0;
}