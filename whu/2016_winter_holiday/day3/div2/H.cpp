#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int rule[27][27];

int main(int argc, char const *argv[])
{
	int lens,lent,n;
	string s,t;
	cin >> s >> t;
	lens = s.length();
	lent = t.length();
	if (lens!=lent)
	{
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			rule[i][j] = 100000;
		}
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char a,b;
		int w;
		cin >> a >> b >> w;
		if (rule[a-'a'][b-'a']>w)
			rule[a-'a'][b-'a']=w;
	}
	for (int i = 0; i < 26; ++i)
	{
		rule[i][i] = 0;
	}
	for (int k = 0; k < 26; ++k)
	{
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				rule[i][j] = min(rule[i][j],rule[i][k]+rule[k][j]);
			}
		}
	}
	long ans = 0;
	string st = s;
	for (int i = 0; i < lens; ++i)
	{
		int k;
		bool ok = false;
		if (s[i]!=t[i])
		{
			int cost1,cost2;
			long sum = 1000000;
			for (int j = 0; j < 26; ++j)
			{
				cost1 = rule[s[i]-'a'][j];
				cost2 = rule[t[i]-'a'][j];
				if (sum>(cost1+cost2)&&cost1!=100000&&cost2!=100000)
				{
					sum = cost1+cost2;
					k = j;
					ok = true;
				}
			}
			if (!ok)
			{
				cout << "-1\n";
				return 0;
			}
			ans+=sum;
			st[i] = 'a'+k;
		}
	}
	cout << ans << endl;
	cout << st << endl;
	return 0;
}