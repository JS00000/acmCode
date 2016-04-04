#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;


int T;
int n, m;
int num[50010];
bool p[50010];
string str;

struct DisjointSet
{
	vector<int> father,rank;
	DisjointSet(int n):father(n),rank(n){
		for (int i = 0; i < n; ++i)
		{
			father[i] = i;
		}
	}
	int find(int v)
	{
		return father[v] = father[v]==v ? v : find(father[v]);
	}
	void merge(int x, int y)
	{
		int a = find(x),b = find(y);
		if (rank[a]<rank[b])
		{
			father[a] = b;
		}
		else
		{
			father[b] = a;
			if (rank[b]==rank[a])
			{
				++rank[a];
			}
		}
	}
};

ll pow(ll a, ll b, ll n)
{
	ll base = a;
	ll r = 1;
	while(b!=0)
	{
		if (b&1) r=r*base%n;
		base=base*base%n;
		b>>=1;
	}
	return r;
}

int main(int argc, char const *argv[])
{
	cin >> T;
	while(T)
	{
		int a,b;
		bool flag = true;
		DisjointSet dis(50010);
		cin >> n >> m;
		cin >> str;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			a--;
			b--;
			if (str[a]!=str[b]&&!(str[a]=='?'||str[b]=='?'))
			{
				flag = false;
			}
			dis.merge(a,b);
		}
		for (int i = 0; i < n/2; ++i)
		{
			dis.merge(i,n-i-1);
		}
		for (int i = 0; i < n; ++i)
		{
			num[i] = -1;
			p[i] = false;
		}
		for (int i = 0; i < n; ++i)
		{
			int fa = dis.find(i);
			char c1 = str[i], c2 = str[fa];
			if (c1=='?'&&c2=='?')
			{
				p[fa] = true;
				num[fa] = 26;
			}
			else if (c1=='?'||c2=='?')
			{
				p[fa] = true;
				num[fa] = 1;
				str[fa] = c1=='?' ? c2 : c1;
			}
			else if (c1==c2)
			{
				p[fa] = true;
			}
			else
			{
				flag = false;
			}
		}
		if (!flag)
		{
			cout << "0\n";
		}
		else
		{
			ll ans = 1;
			ll sum = 0;
			for (int i = 0; i < n; ++i)
				if (p[i]&&num[i]==26) sum++;
			ans = pow(26,sum,1000000007);
			cout << ans << endl;
		}
		T--;
	}
	return 0;
}