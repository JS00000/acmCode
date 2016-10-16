#include <set>
#include <map>
#include <ctime>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define mod 20101009
#define inf 1000000000
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int ans;
int K;
int n,tot = 0;
int prime[1000005];
bool mark[1000005];
void prime_init()
{
    memset(mark, 0, sizeof(mark));
    for(int i=2;i<=1000000;i++)
    {
        if(!mark[i])prime[++tot]=i;
        for(int j=1;j<=tot&&prime[j]*i<=1000000;j++)
        {
            mark[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int Euler(int n)
{
    int ans=n;
    for(int i=1;prime[i]<=sqrt(n);i++)
        if(n%prime[i]==0)
        {
            ans=(ans-ans/prime[i]);
            while(n%prime[i]==0) n/=prime[i];
        }
    if(n!=1)ans=(ans-ans/n);
    return ans%K;
}
int qpow(int a,int b)
{
    int ans=1;a%=K;
    for(int i=b;i;i>>=1,a=a*a%K)
        if(i&1)ans=ans*a%K;
    return ans;
}

int main()
{
    prime_init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &K);
        ans=0;
        for(int i=1;i*i<=n;i++)
            if(n%i==0)
            {
                ans+=Euler(i)*qpow(n,n/i-1);
                if(i*i!=n)ans+=Euler(n/i)*qpow(n,i-1);
                ans%=K;
            }
        printf("%d\n",ans);
    }
    return 0;
}
