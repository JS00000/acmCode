
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 ;
typedef __int64  LL;
LL  a[maxn];
int main()
{
    LL  l,r,k;
    while(scanf("%I64d%I64d%I64d",&l,&r,&k)!=EOF)
    {
        int len=0;
        LL  temp=1;
        for(int i=0; i<63; i++)
        {
            if(temp>=l&&temp<=r)
            {
                a[len++]=temp;
            }
            if(r/temp>=k)
                temp*=k;
            else
                break;
        }
        if(len)
        {
            printf("%I64d",a[0]);
            for(int i=1; i<len; i++)
                printf(" %I64d",a[i]);
            putchar('\n');
        }
        else
            puts("-1");
    }
    return 0;
}