#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
using namespace std;

#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; i++)
#define Rof(i,a,b) for (int i=(a),_##i=(b); i>=_##i; i--)


const int maxn=4e5+100;
int N,M,boy[maxn];
vector <int> g[maxn];
map <int,int> b[maxn];
int girl_chose[maxn];
map <int,int> :: iterator boy_chose[maxn];
queue <int> Q;

long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if (b==0)
    {
        x=1,y=0;
        return a;
    }
    long long d=exgcd(b,a%b,x,y);
    long long tmp=x;
    x=y;
    y=tmp-a/b*y;
    return d;
}

void minimal_x(long long a,long long b,long long &x,long long &y)
{
    if (b<0) a=-a,b=-b;
    long long t=x/b;
    x-=t*b;
    y+=t*a;
    if (x<0) x+=b,y-=a;
}

int get_step(int i,int j) // 璁＄畻鐢风敓i瀵瑰コ鐢焜鐨勫枩娆㈢▼搴�
{
    long long a,b,c,d,x,y;
    a=i,b=M,c=j-boy[i];
    d=exgcd(a,b,x,y);
    if (c%d!=0) return -1;
    a/=d,b/=d,c/=d;
    x*=c,y*=c;
    minimal_x(a,b,x,y);
    return x;
}

int solve()
{
    For(i,0,N-1) b[i].clear();
    For(j,0,M-1)
        For(k,0,g[j].size()-1)
        {
            int i=g[j][k];
            int step=get_step(i,j);
            if (step!=-1)
                b[i][step]=j;
        }
    For(j,0,M-1) girl_chose[j]=-1; // -1鏍囪涓烘病鏈夐�夋嫨
    For(i,0,N-1) boy_chose[i]=b[i].begin();
    for (; !Q.empty(); Q.pop());
    For(i,0,N-1) Q.push(i);
    for (; !Q.empty(); Q.pop())
    {
        int i=Q.front();
        if (boy_chose[i]==b[i].end()) continue;
        int j=boy_chose[i]->second;
        if (girl_chose[j]==-1)
            girl_chose[j]=i;
        else if (girl_chose[j]>i)
        {
            int last_i=girl_chose[j];
            girl_chose[j]=i;
            boy_chose[last_i]++;
            Q.push(last_i);
        }
        else
        {
            boy_chose[i]++;
            Q.push(i);
        }
    }
    int ans=0;
    For(i,0,N-1)
        ans+=(boy_chose[i]==b[i].end());
    return ans;
}

int main()
{
    int zz=0;
    scanf("%d",&zz);
    For(test,1,zz)
    {
        scanf("%d%d",&N,&M);
        For(i,0,N-1) scanf("%d",&boy[i]);
        For(j,0,M-1)
        {
            int y;
            scanf("%d",&y);
            g[j].clear();
            g[j].push_back(y);
            if (j>0)
            {
                for (y+=j; y<N; y+=j)
                    g[j].push_back(y);
            }
        }
        int ans=solve();
        printf("CASE #%d: %d\n",test,ans);
    }
    return 0;
}
