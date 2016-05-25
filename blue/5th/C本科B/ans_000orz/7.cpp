#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	bool p[30], flag;
	int a,b,c,d,e,f,g,h,i,j;
	for (b = 1; b <= 12; ++b)
	{
		d = 15-b;
		for (a = 1; a <= 12; ++a)
		{
			c = 25-b-a;
			for (e = 1; e <= 12; ++e)
			{
				f = 26-c-d-e;
				for (i = 1; i <= 12; ++i)
				{
					h = 18-a-i;
					g = 25-i-f;
					for (j = 1; j <= 12; ++j)
					{
						p[j] = false;
					}
					if (a<1||b<1||c<1||d<1||e<1||f<1||g<1||h<1||i<1)
					{
						continue;
					}
					p[1] = true;
					p[3] = true;
					p[8] = true;
					p[a] = true;
					p[b] = true;
					p[c] = true;
					p[d] = true;
					p[e] = true;
					p[f] = true;
					p[g] = true;
					p[h] = true;
					p[i] = true;
					flag = true;
					for (j = 1; j <= 12; ++j)
					{
						if (!p[j])
						{
							flag = false;
						}
					}
					if (flag)
					{
						cout << b << endl;
					}
				}
			}
		}
	}
	return 0;
}