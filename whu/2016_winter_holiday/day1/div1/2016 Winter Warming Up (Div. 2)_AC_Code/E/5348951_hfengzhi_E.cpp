#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL __int64
#define INF 0x3f3f3f3f
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

int hoge,foo,bar,t,n,m;
long long  a;
long long  d[200005];
int main()
{
    scanf("%d",&n);
    long long  beg=1,ens=1;
    long long  minn=0x3f3f3f3f3f3f;
    long long  ens1=1,beg1=1;
    long long  maxn=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&d[i]);
        if(minn>d[i])
        {
            minn=d[i];
            beg=ens=i;
            beg1=ens1=i;
            maxn=0;
        }
        else if(minn==d[i])
        {
            ens=i;
            if(maxn<(ens1-beg1))
                maxn=ens1-beg1;
                beg1=ens1=i;
        }
        else
            ens1++;
    }
    long long ans=0;
    long long a=0;
        a=n-(ens-beg+1);
    ans+=(minn*n+max(a,maxn));
    printf("%lld\n",ans);
    return 0;
}
