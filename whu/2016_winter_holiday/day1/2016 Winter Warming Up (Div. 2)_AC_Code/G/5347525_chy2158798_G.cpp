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

ULL l,r,k;


int main()
{
    bool flag = false;
    int sum = 0;
    cin>>l>>r>>k;
    ULL s = 1;

    while(s<(double)l/k) s*=k;
    if ( s>(double)r/k && l!=1)
    {
        puts("-1");
        return 0;
    }
    if ( s<l ) s*=k;
    while( s<=r )
    {
        if ( flag ) putchar(' ');
        cout<<s;

        sum++;
        flag = true;
        if ( s<= (double)r/k) s*=k;
        else break;
    }
    if ( !sum ) puts("-1");
    return 0;
}

