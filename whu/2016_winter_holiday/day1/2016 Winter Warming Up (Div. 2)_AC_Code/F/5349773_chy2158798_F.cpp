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
const int maxn = (1<<9)+2;

int k;

int ans[maxn][maxn];

void make(int ans[maxn][maxn],int len)
{
    rep(i,len+1,len*2)
        rep(j,1,len)
        ans[i][j] = ans[i-len][j];
    rep(i,len+1,len*2)
        rep(j,len+1,len*2)
            ans[i][j] = ans[i][2*len+1-j];
    rep(i,1,len)
        rep(j,len+1,len*2)
        ans[i][j] = 1 - ans[i][2*len+1-j];
}

int main()
{
    cin>>k;
    Clean(ans,0);
    if ( k==0 )
    {
        puts("+");
        return 0;
    }
    ans[1][1] = ans[1][2] = ans[2][1] = 1;
    int l = 2;
    rep(i,1,k-1)
    {
        make(ans,l);
        l<<=1;
    }
    rep(i,1,l)
    {
        rep(j,1,l) putchar( (ans[i][j]==1)?'+':'*' );
        putchar('\n');
    }
    return 0;
}

