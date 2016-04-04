#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <utility>
using namespace std;

#define rep(i,j,k) for (int i=j;i<=k;i++)
#define Rrep(i,j,k) for (int i=j;i>=k;i--)

#define Clean(x,y) memset(x,y,sizeof(x))
#define LL long long
#define ULL unsigned long long
#define inf 0x7fffffff
#define mod %100000007
const int maxn = 200009;

LL ans;
int n;
int a[maxn];
int mm;

int main()
{
    mm = 1000000000;
    cin>>n;
    rep(i,1,n)
    {
        scanf("%d",a+i);
        mm = min(mm,a[i]);
    }
    rep(i,1,n) a[i]-=mm;
    ans+=(LL)mm*n;
    int x1 = 0;
    int temp = 0;
    rep(i,1,n)
    {
        if ( a[i]  ) temp++;
        if ( 0==a[i] )
        {
            x1 = max(x1,temp);
            temp = 0;
        }
    }
    x1 = max(x1,temp);
    int x2 = 0;
    temp = 0;
   rep(i,1,n) if ( a[i] ) x2++;
    else break;
    Rrep(i,n,1) if ( a[i] ) x2++;
    else break;
    ans+=max(x1,x2);
    cout<<ans<<endl;
    return 0;
}

