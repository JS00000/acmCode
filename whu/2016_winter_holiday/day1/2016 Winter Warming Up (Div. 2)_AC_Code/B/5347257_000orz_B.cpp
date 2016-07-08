#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	int x,y,x0,y0;
	char com[100001];
	int lx, ly;
	bool p[501][501] = {false};
	int sum = 1;
	cin >> x >> y >> x0 >> y0;
	cin >> com;
	lx = x0;
	ly = y0;
	cout << "1";
	p[x0][y0] = true;
	for (int i = 0; i < strlen(com)-1; ++i)
	{
		if (com[i]=='U')
		{
			if (lx>1)
			{
				lx-=1;
			}
		}
		if (com[i]=='D')
		{
			if (lx<x)
			{
				lx+=1;
			}
		}
		if (com[i]=='L')
		{
			if (ly>1)
			{
				ly-=1;
			}
		}
		if (com[i]=='R')
		{
			if (ly<y)
			{
				ly+=1;
			}
		}
		if (!p[lx][ly])
		{
			p[lx][ly] = true;
			cout << " 1";
			sum++;
		}
		else
		{
			cout << " 0";
		}
	}
	cout << " " << x*y-sum << endl;
	return 0;
}
