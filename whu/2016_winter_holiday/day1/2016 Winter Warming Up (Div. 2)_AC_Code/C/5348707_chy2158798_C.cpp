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
const int maxn = 100009;

int n;
int pos[maxn];
int f[maxn];
int a[maxn];

int temp;

int main()
{
    cin>>n;
    rep(i,1,n)
    {
        scanf("%d",&temp);
        pos[temp] = i;
        f[i] = 1;
    }
    int ans = 1;
    rep(i,2,n)
    {
        if ( pos[i]>pos[i-1] )
        {
            f[i] = f[i-1]+1;
        }
    }
    rep(i,1,n) ans = max(ans,f[i]);
    cout<<n-ans<<endl;
    return 0;
}

