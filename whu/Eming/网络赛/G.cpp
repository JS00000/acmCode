#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	int T,n,m,p,q;
	string mp[1000],dir;
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> p >> q;
		p--;
		q--;
		for (int i = 0; i < n; ++i)
		{
			cin >> mp[i];
		}
		cin >> dir;
		for (int i = 0; i < dir.length(); ++i)
		{
			if (dir[i]=='S')
			{
				while(p<n-1&&mp[p+1][q]=='*') p++;
			}else
			if (dir[i]=='N')
			{
				while(p>0&&mp[p-1][q]=='*') p--;
			}else
			if (dir[i]=='E')
			{
				while(q<m-1&&mp[p][q+1]=='*') q++;
			}else
			if (dir[i]=='W')
			{
				while(q>0&&mp[p][q-1]=='*') q--;
			}
		}
		cout << ++p << " " << ++q << endl;
	}
	return 0;
}