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
int main()
{
    LL n;
    cin>>n;
    LL sum = 0;
    if ( n&1 )
    {
        puts("0");
        return 0;
    }
    n>>=1;
    sum = n>>1;
    if ( (n&1)==0 ) sum--;
    cout<<sum<<endl;
    return 0;
}
