#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[50005];

int main()
{
    int i,j,minn,maxn,n,ans;
    scanf("%d",&n);
    for(i = 1;i<=n;i++)
    scanf("%d",&a[i]);
    ans = 0;
    for(i = 1;i<=n;i++)
    {
        minn = n;
        maxn = 1;
        for(j = i;j<=n;j++)
        {
            maxn = max(maxn,a[j]);
            minn = min(minn,a[j]);
            if(maxn-minn == j-i)
            ans++;
        }
    }
    printf("%d\n",ans);

    return 0;
}
