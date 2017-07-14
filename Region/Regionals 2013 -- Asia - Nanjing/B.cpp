#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 10
#define eps 1e-9
using namespace std;
int main()
{
    int i,j,k;
    double x,y;
    while(scanf("%lf%lf",&x,&y)!=EOF)
    {
        if(x-y>eps)
        {
            puts("-1");
            continue;
        }
        int ans=(int)(x+eps-1);
        printf("ans=%d\n", ans);
        double now=1.0;
        double sum=0.0;
        for(i=1;i<=(int)(x+eps);i++)
        {
            sum=now*i;
            k=(int)(y/x*i-sum);
            ans+=k;
            now+=(double)k/i;
            if((sum+k+1)/i*x-y<1.0)
            {
                now+=1.0/i;
                ans++;
            }
        }
        if(now<(double)y/x)ans++;
        printf("%d\n",ans);
    }
    return 0;
}