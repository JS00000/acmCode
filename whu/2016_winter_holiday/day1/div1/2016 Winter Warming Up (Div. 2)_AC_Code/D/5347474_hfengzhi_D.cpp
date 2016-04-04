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

int hoge,foo,bar,t,n,m;
int a;
int main()
{
 scanf("%d",&n);
  if(n%2==1)
    puts("0");
  else
  {
      n/=2;
      n-=1;
      n/=2;
      printf("%d\n",n);
  }

    return 0;
}
