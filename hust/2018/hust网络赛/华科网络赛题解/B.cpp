#include<iostream>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;
const int maxn = 1e5+10;
string s;
ll m;

ll q_pow(ll x, ll k){
    ll res = 1;
    while(k > 0){
        if(k&1) res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}

ll inverse(ll x){
    return q_pow(x, mod-2);
}

int main()
{
    cin >> m >> s;
    ll ans = 0, q = q_pow(2, s.size()), deno, memb;
    deno = inverse((q-1+mod)%mod);
    memb = (q_pow(q, m)-1+mod)%mod;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '0' || s[i] == '5')
            ans = (ans + q_pow(2,i)*deno%mod*memb%mod)%mod;
    cout << ans << endl;
    return 0;
}
