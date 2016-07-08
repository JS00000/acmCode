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


int num;
int n;
char ans[maxn];
char str[maxn];

bool check(char s[])
{
    int fz = 0;
    int len = strlen( s );
    rep(i,0,len-1)
    {
        if ( !(s[i]=='0'||s[i]=='1') ) return false;
        if ( s[i]=='1' ) fz++;
    }
    return fz<=1;
}


int calcu(char s[])
{
    int len = strlen(s);
    int ans = 0;
    rep(i,1,len-1)
        if ( s[i]=='0' ) ans++;
    return ans;
}

int main()
{
    num = 0;
    bool flag = false;
    bool x = false;
    cin>>n;

    rep(i,1,n)
    {
        scanf("%s",str);
        if ( str[0]=='0' ) flag = true;
        if ( check(str) ) num+=calcu(str);
        else
        {
            x = true;
                int len = strlen(str);
                rep(i,0,len) ans[i] = str[i];

        }
    }

    if ( flag )
        puts("0");
    else
    {
        if ( x )
        cout<<ans;
        else putchar('1');
        rep(i,1,num) putchar('0');
        cout<<endl;
    }
    return 0;
}

