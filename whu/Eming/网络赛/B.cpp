#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int T,N,k,p,k1,k2,p1,p2,syn,n,m,t;
int pos[2];
string mp[233333];
bool status[9];

int main(int argc, char const *argv[])
{
	/* code */
	cin >> T >> N;
	for (int i = 0; i < T; ++i)
	{
		mp[i] = ".........";
	}
	for (int m = 0; m < N; ++m)
	{
		cin >> n >> t;
		t--;
		int j = 1;
		if (n==4) j = 2;
		while(j--)
		{
			cin >> k >> p;
			p--;
			if (k==1)
			{
				mp[t][p] = 'O';
			}
			else
			{
				mp[t][p] = 'l';
			}
		}

	}
	for (int i = 0; i < 9; ++i)
	{
		status[i] = 0;
	}
	for (int i = 0; i < T; ++i)
	{
		syn = 0;
		for (int j = 0; j < 9; ++j)
		{
			if (mp[i][j]=='O')
			{
				pos[syn] = j;
				syn++;
			} else if (mp[i][j]=='l')
			{
				status[j] ^= 1;
				pos[syn] = j;
				syn++;
			} else if(status[j] == 1)
			{
				mp[i][j] = '|';
			}
		}

		if (syn==1)
		{
			if (mp[i][pos[0]]=='l' && status[pos[0]]==1)
			{
				mp[i][pos[0]] = '^';
			}
			else if(mp[i][pos[0]]=='l' && status[pos[0]]==0)
			{
				mp[i][pos[0]] = 'v';
			}
		}
		else if (syn==2)
		{
			if (mp[i][pos[0]]=='O'&&mp[i][pos[1]]=='O')
			{
				mp[i][pos[0]] = '-';
				mp[i][pos[1]] = '-';
			}
			else if(mp[i][pos[0]]=='O'&&mp[i][pos[1]]=='l'&&status[pos[1]]==1)
			{
				mp[i][pos[0]] = '-';
				mp[i][pos[1]] = '*';
			}
			else if(mp[i][pos[1]]=='O'&&mp[i][pos[0]]=='l'&&status[pos[0]]==1)
			{
				mp[i][pos[1]] = '-';
				mp[i][pos[0]] = '*';
			}
			else if(mp[i][pos[0]]=='O'&&mp[i][pos[1]]=='l'&&status[pos[1]]==0)
			{
				mp[i][pos[1]] = 'v';
			}
			else if(mp[i][pos[1]]=='O'&&mp[i][pos[0]]=='l'&&status[pos[0]]==0)
			{
				mp[i][pos[0]] = 'v';
			}
			else if(mp[i][pos[0]]=='l'&&mp[i][pos[1]]=='l'&&status[pos[0]]==0&&status[pos[1]]==0)
			{
				mp[i][pos[1]] = 'v';
				mp[i][pos[0]] = 'v';
			}
			else if(mp[i][pos[0]]=='l'&&mp[i][pos[1]]=='l'&&status[pos[0]]==1&&status[pos[1]]==1)
			{
				mp[i][pos[1]] = '*';
				mp[i][pos[0]] = '*';
			}
			else if(mp[i][pos[0]]=='l'&&mp[i][pos[1]]=='l'&&status[pos[0]]==1&&status[pos[1]]==0)
			{
				mp[i][pos[1]] = 'v';
				mp[i][pos[0]] = '^';
			}
			else if(mp[i][pos[0]]=='l'&&mp[i][pos[1]]=='l'&&status[pos[0]]==0&&status[pos[1]]==1)
			{
				mp[i][pos[1]] = '^';
				mp[i][pos[0]] = 'v';
			}
		}
	}
	for (int j = 0; j < 9; ++j)
	{
		if (status[j]==1)
		{
			mp[T-1][j] = 'v';
		}
	}
	for (int i = 0; i < T; ++i)
	{
		cout << mp[i] << endl;
	}
	return 0;
}