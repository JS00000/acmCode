#include <stdio.h>
#include <iostream>
#include <deque>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
const ll aa = 2333;

int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        printf("CASE #%d: ",cas);
        int q;
        scanf("%d",&q);
        deque<ll> dq;
        ll len=0;
        ll ans=0;
        while(q--)
        {
            ll x;
            scanf("%lld",&x);
            if(x==-1)
            {
                if(!dq.empty())
                {
                    len = (len-1) % mod;
                    ans = ((ans * aa) % mod + dq.front()) % mod;
                    dq.pop_front();
                }
            }
            else if(x==0)
            {
                ll len1=(ll)dq.size();
                for(ll i=0;i<len1;i++)
                {
                    if(len+i>100005) break;
                    dq.push_back(dq[i]);
                }
                len = len * 2 % mod;
                ans = ((ans * aa) % mod + len) % mod;
            }
            else
            {
                len = (len+1) % mod;
                dq.push_front(x);
                ans = ((ans * aa) % mod + len) % mod;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
