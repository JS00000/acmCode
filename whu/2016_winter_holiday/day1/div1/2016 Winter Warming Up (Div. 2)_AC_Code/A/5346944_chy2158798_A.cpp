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

int n;
int a,b,c;
int x,y,z;
int s1,s2;

bool check()
{
    if ( a==x && b==y && c==z ) return true;
    s1 = a+b+c;
    s2 = x+y+z;
    if ( s1<=s2 ) return false;
    int time = s1-s2;
    int sum = 0;
    if ( a>x ) sum+=(a-x)/2;
    if ( b>y ) sum+=(b-y)/2;
    if ( c>z ) sum+=(c-z)/2;
    if ( a<x ) sum-=(x-a);
    if ( b<y ) sum-=(y-b);
    if ( c<z ) sum-=(z-c);
    return sum>=0;

}

int main()
{
    cin>>a>>b>>c;
    cin>>x>>y>>z;
    s1 = a+b+c;
    s2 = x+y+z;
    puts(check()?"Yes":"No");
    return 0;
}

