#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000007
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int n,tot = 0;
int prime[maxn+7];
bool mark[maxn+7];
void prime_init()
{
    memset(mark, 0, sizeof(mark));
    for(int i=2;i<=maxn;i++)
    {
        if(!mark[i])prime[++tot]=i;
        for(int j=1;j<=tot&&prime[j]*i<=maxn;j++)
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
    return ans;
}

double f(int a, int b)
{
    return double(Euler(a*b))/Euler(a)/Euler(b);
}

int lkp[5] = {1, 2, 6, 210, 30030};

int main()
{
    prime_init();
    double rr = 0;
    for (int i = 1; i <= 7; i++)
        for (int j = 1; j <= 7; j++)
            if (f(i, j) > 0) {
                printf("%d %d %f\n", i, j, f(i, j));
                rr += f(i, j);
            }
    printf("%f\n", rr);
    // int T;
    // scanf("%d", &T);
    // long long m, n, p;
    // while (T--) {
    //     scanf("%lld%lld%lld", &m, &n, &p);
    //     long long ans = 0, t = 0, res = 0;
    //     for (int i = 4; i >= 0; i--) {
    //         t = (m / lkp[i]) * (n / lkp[i]);
    //         printf("(t - res) * (i+1) = %lld\n", (t - res) * (i+1));
    //         ans = (ans + (t - res) * (i+1)) % p;
    //         printf("ans = %lld\n", ans);
    //         res += t;
    //         printf("res = %lld\n", res);
    //     }
    //     printf("%lld\n", ans);
    // }
    return 0;
}
