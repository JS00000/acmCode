#include <map>
#include <cstdio>

using namespace std;
typedef long long ll;
int T;
int n,tot;
ll k;
int a[200009];
int num[200009];
map<int,int> ma;
bool check(ll x){
    ll kk=0,now=0,l=0;
    for(int i=0;i<tot;++i)num[i]=0;
    for(int i=0;i<n;++i){
        now+=num[a[i]]++;
        while(now>x){
            now-=--num[a[l++]];
        }
        kk+=i-l+1;
    }
    return kk>=k;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%lld",&n,&k);
        ma.clear();tot=0;
        ll l=0,r=(ll)n*(n-1)/2;
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            if(ma.find(a[i])==ma.end())ma[a[i]]=tot++;
            a[i]=ma[a[i]];
        }
        while(l<=r){
            ll mid=(l+r)>>1;
            if(check(mid))r=mid-1;
            else l=mid+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}
