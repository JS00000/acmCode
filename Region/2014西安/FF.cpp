#include <iostream>  
using namespace std;  
  
const int MOD = 1000000007;  
const int MAXN = 1000010;  
int nCase, cCase;  
long long n, m, k, ans1, ans2, C[MAXN];  
  
inline long long pow_mod(long long p, long long k) {  
    long long ans = 1;  
    while (k) {  
        if (k & 1) {  
            ans = (ans * p) % MOD;  
        }  
        p = (p * p) % MOD;  
        k >>= 1;  
    }  
    return ans;  
}  
  
inline long long inverse(long long num) {  
    return pow_mod(num, MOD-2);  
}  
  
void calcC(long long n) {  
    C[0] = 1;  
    for (int i = 1; i <= k; i++) {  
        C[i] = ((C[i-1] * (n-i+1)) % MOD) * inverse(i) % MOD;  
    }  
}  
  
void solve() {  
    calcC(m);  
    ans1 = C[k];  
  
    calcC(k);  
    ans2 = 0;  
    int sgn = 1;  
    for (int l = k; l >= 1; l--) {  
        ans2 = (ans2 + (sgn * l * pow_mod(l-1, n-1)) % MOD * C[l] % MOD + MOD) % MOD;  
        sgn = -sgn;  
    }  
  
    cout << "Case #" << ++cCase << ": " << ans1*ans2 % MOD << endl;  
}  
  
int main() {  
    ios::sync_with_stdio(false);  
    cin >> nCase;  
    while (nCase--) {  
        cin >> n >> m >> k;  
        solve();  
    }  
    return 0;  
}  