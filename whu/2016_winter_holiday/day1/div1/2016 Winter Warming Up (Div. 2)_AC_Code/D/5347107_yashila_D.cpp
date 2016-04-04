#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll ans = n / 4;
	if (n % 4 == 0) ans--; 
	if (n % 2 == 1) cout << 0;
	else cout << ans << endl;
	return 0;
}