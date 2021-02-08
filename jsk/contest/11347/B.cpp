#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100007
using namespace std;

typedef long long ll;

struct node
{
	string name;
	ll v;
} p[maxn];

bool cmp(node a, node b)
{
	return a.v < b.v;
}

int main()
{
	int n;
	ll L;
	cin >> n >> L;
	for (int i = 0; i < n; i++) {
		cin >> p[i].name >> p[i].v;
	}
	sort(p, p+n, cmp);
	for (int i = 0; i < n-1; i++) {
		cout << p[i].name << " " << (i+1) * p[i].v / L << " " << (L - (i+1) * p[i].v % L) % L << endl;
	}
	cout << p[n-1].name << endl;
	return 0;
}
