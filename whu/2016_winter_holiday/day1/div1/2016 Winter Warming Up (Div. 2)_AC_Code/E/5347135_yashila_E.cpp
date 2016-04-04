#include<bits/stdc++.h>

using namespace std;

const int N = 200000 + 1000;
typedef long long ll;
int a[2 * N], n, f[2 * N];

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	int id, mn = 1e9 +100;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		a[i + n] = a[i];	
		if (a[i] <= mn){
			mn = a[i];
			id = i;
		}
	}
	ll ans = 0;
	ans = 1LL* mn * n;
	for (int i = 0; i < 2 * n; i++) a[i] -= mn;
	if (a[0]) f[0] = 1;
	for (int i = 0; i < 2 * n; i++){
		if (a[i]) f[i] = f[i - 1] + 1;
		else f[i] = 0;
	}
	int mx = 0;
	for (int i = 0; i < 2 * n; i++) if (f[i] > mx) mx = f[i];
	cout << ans + 1LL*mx << endl;
	return 0;
}