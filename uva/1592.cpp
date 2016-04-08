#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, int> IDcache;
vector<string> STRcache;

int mp[10000][10];

int ID(string x)
{
	if (IDcache.count(x)) return IDcache[x];
	STRcache.push_back(x);
	return IDcache[x] = STRcache.size() - 1;
}

map<pair<int, int>, int> fun;

int main(int argc, char const *argv[])
{
	int n,m;
	while(cin >> n >> m)
	{
		IDcache.clear();
		STRcache.clear();
		fun.clear();
		for (int i = 0; i < n; ++i)
		{
			string str;
			char c;
			int id;
			for (int j = 0; j < m-1; ++j)
			{
				str = "";
				while(',' != (c = getchar()))
				{
					str += c;
				}
				id = ID(str);
				mp[i][j] = id;
			}
			cin >> str;
			id = ID(str);
			mp[i][m-1] = id;
		}
		bool flag = true;
		pair<int, int> ansr, ansc;
		for (int c1 = 0; c1 < m-1; ++c1)
		{
			if (!flag) break;
			for (int c2 = c1+1; c2 < m; ++c2)
			{
				if (!flag) break;
				for (int r = 0; r < n; ++r)
				{
					pair<int, int> temp(mp[r][c1], mp[r][c2]);
					if (!flag) break;
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
					}
				}
			}
		}
		if (flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n" << ansr.first + 1 << " " << ansr.second + 1 << "\n" << ansc.first + 1 << " " << ansc.second + 1 << "\n";
		}

	}
	return 0;
}