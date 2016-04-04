#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1000;

int a[N], dp[N], n;

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a[x] = 1;
		if (a[x - 1]) dp[x] = dp[x - 1] + 1;
	}
	int max = 0;
	for (int i = 1; i <= n; i++){
		if (dp[i] > max) max = dp[i];
	}
	cout << n - max - 1 << endl;
	return 0;
}