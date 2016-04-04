#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
int a,b,c,x,y,z;  
long long ans,pre;  
int main()  
{  
    while(scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z)!=EOF)  
    {  
        ans=pre=0;  
        int p,q,r;  
        p=q=r=0;  
        if(a-x>=0) p=0,pre+=(a-x)/2;  
        else p=a-x;  
        if(b-y>=0) q=0,pre+=(b-y)/2;  
        else q=b-y;  
        if(c-z>=0) r=0,pre+=(c-z)/2;  
        else r=c-z;  
        if(pre+p+q+r>=0) printf("Yes\n");  
        else printf("No\n");  
    }  
    return 0;  
}  