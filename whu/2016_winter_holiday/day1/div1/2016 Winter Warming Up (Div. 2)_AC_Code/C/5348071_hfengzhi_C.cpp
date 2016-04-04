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
int a;
 int d[100005];
int main()
{
    memset(d,0,sizeof(d));
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
    scanf("%d",&a);
     d[a]=d[a-1]+1;
 }
 int maxx=1;
 for(int i=1;i<=n;i++)
 {
     if(d[i]>maxx)
        maxx=d[i];
 }
 printf("%d\n",n-maxx);
    return 0;
}
