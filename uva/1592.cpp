#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

typedef long long LL;

map<string, LL> IDcache;
vector<string> STRcache;

LL mp[10010][11];

LL ID(string x)
{
	if (IDcache.count(x)) return IDcache[x];
	STRcache.push_back(x);
	return IDcache[x] = STRcache.size() - 1;
}

map<pair<LL, LL>, LL> fun;

int main(int argc, char const *argv[])
{
	int n,m;
	while(cin >> n >> m)
	{
		getchar();
		IDcache.clear();
		STRcache.clear();
		memset(mp,0,sizeof(mp));
		string line;
		string str;
		for (int i = 0; i < n; ++i)
		{
			getline(cin, line);
			int j = 0;
			str.clear();
			for (int k = 0; k < line.length(); ++k)
			{
				if (line[k]==',')
				{
					mp[i][j++] = ID(str);
					str.clear();
				}
				else
				{
					str += line[k];
				}
			}
			mp[i][j] = ID(str);
		}
		bool flag = true;
		pair<LL, LL> ansr, ansc;
		for (int c1 = 0; c1 < m-1; ++c1)
		{
			if (!flag) break;
			for (int c2 = c1+1; c2 < m; ++c2)
			{
				if (!flag) break;
				fun.clear();
				for (int r = 0; r < n; ++r)
				{
					pair<int, int> temp(mp[r][c1], mp[r][c2]);
					if (!fun.count(temp))
					{
						fun[temp] = r;
					}
					else
					{
						flag = false;
						ansr.first = fun[temp];
						ansr.second = r;
						ansc.first = c1;
						ansc.second = c2;
						break;
					}
				}
			}
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n" << ansr.first + 1 << " " << ansr.second + 1 << "\n" << ansc.first + 1 << " " << ansc.second + 1 << "\n";
	}
	return 0;
}
