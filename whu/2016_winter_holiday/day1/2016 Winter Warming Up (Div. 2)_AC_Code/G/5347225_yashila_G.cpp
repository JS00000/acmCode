#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll l, r, k;
ll maxval = 1e18;

int main(){
	cin >> l >> r >> k;
	ll p = 1;
	int flag = 0;
	while (1){
		if (p >= l && p <= r){
			cout << p << " ";
			flag = 1;
		}
		if (p <= maxval / k) p *= k;
		else break;
	}
	if (!flag) cout << -1 << endl;
	return 0;
}