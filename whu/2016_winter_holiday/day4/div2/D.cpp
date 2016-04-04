#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	while(T)
	{
		string mp[9];
		bool valid = true;
		bool num[10];
		for (int i = 0; i < 9; ++i)
		{
			cin >> mp[i];
			memset(num,false,sizeof(num));
			for (int j = 0; j < 9; ++j)
				num[mp[i][j]-'0'] = true;
			for (int j = 1; j < 10; ++j)
				if (!num[j])
				{
					valid = false;
					// cout << "Invalid1\n";
				}
		}
		for (int i = 0; i < 9; ++i)
		{
			memset(num,false,sizeof(num));
			for (int j = 0; j < 9; ++j)
				num[mp[j][i]-'0'] = true;
			for (int j = 1; j < 10; ++j)
				if (!num[j])
				{
					valid = false;
					// cout << "Invalid2\n";
				}
		}
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				memset(num,false,sizeof(num));
				for (int k = 0; k < 9; ++k)
					num[mp[i*3+k/3][j*3+k%3]-'0'] = true;
				for (int j = 1; j < 10; ++j)
					if (!num[j])
					{
						valid = false;
						// cout << "Invalid3\n";
					}
			}
		}
		if (valid)
			cout << "Valid\n";
		else 
			cout << "Invalid\n";
		getchar();
		T--;
	}
	return 0;
}