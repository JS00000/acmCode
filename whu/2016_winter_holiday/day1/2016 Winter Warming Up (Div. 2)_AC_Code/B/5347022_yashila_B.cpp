#include<bits/stdc++.h>

using namespace std;

int n,m,x,y;
int v[600][600]={0};

int ok(char c){
	if (c == 'U' && x > 1) return 1;
	if (c == 'D' && x < n) return 1;
	if (c == 'L' && y > 1) return 1;
	if (c == 'R' && y < m) return 1;
	return 0;
}

void move(char c){
	if (c == 'U' && x > 1) x -= 1;
	if (c == 'D' && x < n) x += 1;
	if (c == 'L' && y > 1) y -= 1;
	if (c == 'R' && y < m) y += 1;
}

void move_back(char c){
	if (c == 'U' && x > 1) x += 1;
	if (c == 'D' && x < n) x -= 1;
	if (c == 'L' && y > 1) y += 1;
	if (c == 'R' && y < m) y -= 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> m >> x >> y;
	cout << 1 << " ";
	string s;
	cin >> s;
	int cnt = 1;
	v[x][y] = 1;
	for (int i = 0; i < s.length() - 1; i++){
//		cout << s[i] << ':' << ok(s[i]) << endl;
//		cout << x << " " << y << endl;
		if (ok(s[i])){
			move(s[i]);
			if (!v[x][y]){
				cout << 1 << " ";
				v[x][y] = 1;
				++cnt;
			}
			else{
				//move_back(s[i]);
				cout << 0 << " ";
			}
		}
		else cout << 0 << " ";
	}
	cout << n * m - cnt << endl;
	return 0; 
}