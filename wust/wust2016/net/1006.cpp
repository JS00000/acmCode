#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
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
const int maxn = 10009;


int s[maxn];

int n,m;
int a[20];

void init(int n)
{
    rep(i,2,n)
        rep(j,1,m)
        if ( i >= a[j] )
        {
            if ( s[i-a[j]] == -1 ) continue;
            if ( s[i] == 1 ) continue;
            s[i] = 0;
            s[i] |= !s[i-a[j]];

        }
}

bool check(int l)
{
    int p = 10000/l;
    rep(i,1,p-1)
    {
        rep(j,1,l) if (  s[ j + (i-1)*l ] != s[ j + i*l ]  ) return false;
    }
    return true;
}

int main()
{
    while( scanf("%d%d",&n,&m) == 2 )
    {
        rep(i,1,m)
        {
            scanf("%d",a+i);
        }
        sort(a+1,a+1+m);
        Clean(s,-1);
        s[0] = 0;
        rep(i,1,m) s[ a[i] ] = 1;

        init(10000);
        int len;
        rep(i,2,5000)
            if ( check(i) )
            {
                len = i;
                break;
            }

        n = (n-1)%len+1;
        n+=len;
        if ( s[n] == 1 )
        {
            int x = 0;
            rep(j,1,m)
            if ( n >= a[j] && s[ n-a[j] ] == 0 )
            {
                x = a[j];
                break;
            }
            if (x)
                printf("%d\n",x);
            else
                puts("No");
        }
        else puts("No");
    }
    return 0;
}
