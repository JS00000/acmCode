#include <iostream>
#include <string>
#include <cstring>

using namespace std;
typedef long long LL;

string s[101];
char part[6] = {'O', '/', '|', '\\', '(', ')'};
bool p[101][101];
LL t;
int h,w,ans;

bool visit(int i, int j)
{
	if (!p[i][j])
	{
		p[i][j] = 1;
		return 1;
	}
	else return 0;
}

void fresh(int i, int j, int pn)
{
	if (i >= 0 && i < h && j >= 0 && j < w && !p[i][j] && s[i][j] == part[pn])
	{
		p[i][j] = 1;
	}
}

int main(int argc, char const *argv[])
{

	cin >> t;
	while(t--)
	{
		cin >> h >> w;
		memset(p,0,sizeof(p));
		for (int i = 0; i < h; ++i)
		{
			cin >> s[i];
		}
		ans = 0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				switch (s[i][j])
				{
					case 'O':
						if (visit(i, j)) ans++;
						fresh(i+1, j-1, 1);
						fresh(i+1, j  , 2);
						fresh(i+1, j+1, 3);
						fresh(i+2, j-1, 4);
						fresh(i+2, j+1, 5);
						break;
					case '/':
						if (visit(i, j)) ans++;
						fresh(i-1, j+1, 0);
						fresh(i  , j+1, 2);
						fresh(i  , j+2, 3);
						fresh(i+1, j  , 4);
						fresh(i+1, j+2, 5);
						break;
					case '\\':
						if (visit(i, j)) ans++;
						fresh(i-1, j-1, 0);
						fresh(i  , j-2, 1);
						fresh(i  , j-1, 2);
						fresh(i+1, j-2, 4);
						fresh(i+1, j  , 5);
						break;
					case '|':
						if (visit(i, j)) ans++;
						fresh(i-1, j  , 0);
						fresh(i  , j-1, 1);
						fresh(i  , j+1, 3);
						fresh(i+1, j-1, 4);
						fresh(i+1, j+1, 5);
						break;
					case '(':
						if (visit(i, j)) ans++;
						fresh(i-2, j+1, 0);
						fresh(i-1, j  , 1);
						fresh(i-1, j+1, 2);
						fresh(i-1, j+2, 3);
						fresh(i  , j+2, 5);
						break;
					case ')':
						if (visit(i, j)) ans++;
						fresh(i-2, j-1, 0);
						fresh(i-1, j-2, 1);
						fresh(i-1, j-1, 2);
						fresh(i-1, j  , 3);
						fresh(i  , j-2, 4);
						break;
					default: break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}