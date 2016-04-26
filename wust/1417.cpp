// 此题有毒
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cstring>

typedef long long LL;

using namespace std;

int main(int argc, char const *argv[])
{
	LL t;
	LL base = 1, p = 1;
	LL a[100];
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i < 40; ++i)
	{
		base *= 2;
		p *= -1;
		a[i] = a[i-1] + base*p;
	}
	map<string, LL> s;
	s["0"] = 0;
	s["-0"] = 0;
	for (int i = 1; i < 40; ++i)
	{
		char temp[100];
		sprintf(temp, "%lld", a[i]);
		s[temp] = i;
		// cout << temp << " ";
	}
	// cout << endl;
	cin >> t;
	while(t--)
	{
		char d[100];
		LL n;
		scanf("%lld %s", &n, d);
		if (s.count(d) && s[d] <= n) printf("%lld\n", s[d]);
		else printf("-1\n");
	}
	return 0;
}