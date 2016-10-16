// polya定理
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;

// 求循环节数
int Polya_single(int perm[], int n)
{   
    int pos,sum=0;
    int visit[n];
    memset(visit,0, sizeof(visit));
    for(int i=0;i<n;i++)
        if(!visit[i])
        {   
            sum++;
            pos=i;
            for(int j=0;!visit[perm[pos]];j++)
            {   
                pos=perm[pos];
                visit[pos]=1;
            }
        }
    return sum;
}

ll gcd(ll n,ll m)
{
    return m==0?n:gcd(m,n%m);
}

ll pow(ll a, ll b)
{
    ll base = a;
    ll r = 1;
    while(b!=0)
    {
        if (b&1) r=r*base;
        base=base*base;
        b>>=1;
    }
    return r;
}

ll Polya(ll Color,ll num)
{
    ll sum=0;
    for(ll i = 1; i <= num;i++)
        sum += pow(Color,gcd(num,i)); //旋转
    if(num&1) sum += num*pow(Color,(num+1)/2); //奇数翻转
    else sum += ( pow(Color,num/2+1) + pow(Color,num/2) ) * (num>>1); //偶数翻转
    return sum/2/num;
}

int main()
{
    ll c, s;
    while(scanf("%lld%lld", &c, &s) && c != 0)
    {
        printf("%lld\n", Polya(c, s));
    }
    return 0;
}
