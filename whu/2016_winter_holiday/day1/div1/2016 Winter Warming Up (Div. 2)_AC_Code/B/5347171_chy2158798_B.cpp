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
int ans[maxn];
int m,n;
int st,ed;

char str[maxn];

bool flag[509][509];

int getx(char c)
{
    if ( c=='U' ) return -1;
    if ( c=='D' ) return 1;
    return 0;
}
int gety(char c)
{
    if ( c=='L' ) return -1;
    if ( c=='R' ) return 1;
    return 0;
}

int main()
{
    cin>>n>>m>>st>>ed;
    scanf("%s",str+1);
    int len = strlen(str+1);
    Clean(ans,0);
    Clean(flag,true);
    flag[st][ed] = false;

    int sum = m*n-1;
    int step = 0;
    ans[0] = 1;

    int tx = st;
    int ty = ed;
    rep(i,1,len)
    {
        step++;

        if ( tx+getx(str[i])>=1 && tx+getx(str[i])<=n ) tx+=getx(str[i]);
        if ( ty+gety(str[i])>=1 && ty+gety(str[i])<=m ) ty+=gety(str[i]);
        if ( flag[tx][ty] )
        {
            flag[tx][ty] = false;
            ans[step]++;
            sum--;
        }
    }
    ans[len]+=sum;
    rep(i,0,len)
    {
        printf("%d",ans[i]);
        if ( i==len ) putchar('\n');
        else putchar(' ');
    }
    return 0;
}

