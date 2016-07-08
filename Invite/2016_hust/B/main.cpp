#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <string>
 
#define LL long long
#define INF 0x3f3f3f3f
#define eps 1e-8
#define MOD 1000000007
#define MAXN (1 << 20)
using namespace std;
 
 
vector<LL> res;
LL cnt[MAXN];
 
LL pow_mod(LL x, int y){
	LL res = 1;
	while (y){
		if (y & 1){
			res = res * x % MOD;
		}
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}
 
void work(LL *res, int len, int deep){
	if (len == 2){
		res[0] = (res[0] + res[0] * res[1]) % MOD;
		return;
	}
 
	--deep;
	LL *left = (LL*)malloc(sizeof(LL)* (len >> 1));
	LL *right = (LL*)malloc(sizeof(LL)*(len >> 1));
 
	for (int i = 0; i < (1 << deep); ++i){
		left[i] = res[i + (1 << deep)];
		right[i] = (res[i] + left[i] + res[i] * left[i]) % MOD;
	}
	work(left, len >> 1, deep);
	work(right, len >> 1, deep);
	for (int i = 0; i < (1 << deep); ++i){
		res[i] = (right[i] - left[i]) % MOD;
		res[i + (1 << deep)] = left[i];
	}
}
 
int main(){
 
	int n, m;
	while (~scanf("%d", &n)){
		int x;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; ++i){
			scanf("%d", &x);
			++cnt[x];
		}
		for (int i = 0; i < MAXN; ++i){
			cnt[i] = pow_mod(2, cnt[i]) - 1;
			//res.push_back(cnt[i]);
		}
		
		work(cnt, MAXN, 20);
		scanf("%d", &m);
		for (int i = 1; i <= m; ++i){
			scanf("%d", &x);
			int ans = (cnt[x] + MOD) % MOD;
			printf("%d ", ans);
		}
		printf("\n");
	}
}