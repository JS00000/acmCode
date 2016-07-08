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

int hoge,foo,bar,t,m;
long long n;
int main()
{
    long long  l,r,k;
     n=1000000000000000000;
         scanf("%lld%lld%lld",&l,&r,&k);
    int  num=0;
      long long a=1;
    int dd=0;
    while(a<l)
    {
        if(dd)
            break;
        if(a>n*1.0/k)
            dd=1;
        a*=k;
    }
    if(a<=r&&dd!=1)
    {
        printf("%lld",a);
        num=1;
         if(a>n*1.0/k)
            dd=1;
        a*=k;
    }
    while(a<=r)
    {
        if(dd)
            break;

        printf(" %lld",a);
      if(a>n*1.0/k)
            dd=1;
        a*=k;
    }
    if(num==0)
        printf("-1");
    puts("");
    return 0;
}
