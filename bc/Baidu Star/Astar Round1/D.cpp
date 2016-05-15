#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	map<string, int> mp;
	string nstr;
	char name[50];
	cin >> t;
	getchar();
	while(t--)
	{
		gets(name);
		sort(name, name + strlen(name));
		nstr = name;
		// cout << nstr.length() << endl;
		if (!mp.count(nstr))
		{
			puts("0");
			mp[nstr] = 0;
		}
		else
		{
			mp[nstr]++;
			printf("%d\n", mp[nstr]);
		}
	}
	return 0;
}