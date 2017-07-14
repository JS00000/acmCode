#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
bool mp[5][5];
string str;

int main(int argc, char const *argv[])
{
	while(cin >> n >> m)
	{
		int sum_x = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> str;
			for (int j = 0; j < m; ++j)
			{
				if (str[j] == '.') mp[i][j] = 0;
				else 
				{
					mp[i][j] = 1;
					sum_x++;
				}
			}
		}
		for (int i = 0; i < sum_x; ++i)
		{
			
		}

		// for (int i = 0; i < n; ++i)
		// {
		// 	for (int j = 0; j < m; ++j)
		// 	{
		// 		printf("%d", mp[i][j]);
		// 	}
		// 	printf("\n");
		// }
	}
	return 0;
}