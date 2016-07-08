#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int k;
	int	w = 1;
	int ve[512][512];
	int last[512][512];
	cin >> k;
	// k = 0;
	if (k==0)
	{
		cout << "+\n";
		return 0;
	}
	ve[0][0] = 1;
	last[0][0] = 1;
	for (int n = 1; n < k+1; ++n)
	{
		w*=2;
		for (int i = 0; i < w/2; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				ve[i][j] = last[i][j/2];
			}
		}
		for (int i = w/2; i < w; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (j%2==0)
				{
					ve[i][j] = -1*ve[i-w/2][j];
				}
				else
				{					
					ve[i][j] = ve[i-w/2][j];
				}	
			}
		}
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				last[i][j] = ve[i][j];
			}
		}
	}
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (ve[i][j]==1)
			{
				cout << '+';
			}
			else
			{
				cout << '*';
			}
		}
		cout << "\n";
	}
	return 0;
}