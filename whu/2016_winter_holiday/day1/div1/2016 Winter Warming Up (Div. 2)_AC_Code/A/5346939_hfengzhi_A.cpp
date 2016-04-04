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
#define maxn 500005
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

int hoge,foo,bar,t,n,m;

int main()
{
   int a,b,c;
   int x,y,z;
   scanf("%d%d%d",&a,&b,&c);
   scanf("%d%d%d",&x,&y,&z);
   int ans=0,an=0;
   if(a>x)
   {
       ans+=(a-x)/2;
   }
   else
    an+=(x-a);

     if(b>y)
   {
       ans+=(b-y)/2;
   }
   else
    an+=(y-b);

     if(c>z)
   {
       ans+=(c-z)/2;
   }
   else
    an+=(z-c);
    if(ans>=an)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
