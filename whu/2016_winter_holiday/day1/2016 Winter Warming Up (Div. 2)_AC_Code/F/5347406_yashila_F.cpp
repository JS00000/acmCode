#include<bits/stdc++.h>

using namespace std;

const int N = 1000 + 100;

int f[N][N];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	f[0][0] = 1;
	int now = 1;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < now; j++)
			for (int k = now; k < now * 2; k++)
				f[j][k] = -f[j][2 * now - k - 1];
		for (int j = now; j < now * 2; j++){
			for (int k = 0; k < now; k++)
				f[j][k] = f[j - now][k];
			for (int k = now; k < 2 * now; k++)
				f[j][k] = f[j][2 * now - k - 1];
		}
		now = 2 * now;
	}
	for (int i = 0; i < (1 << n); i++){
		for (int j = 0; j < (1 << n); j++)
			if (f[i][j] == 1) cout << '+';
			else cout << '*';
		cout << endl;
	}
	return 0;
}