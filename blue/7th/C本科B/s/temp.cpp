#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>

#define LL long long
#define MAXN 0x0fffffff

using namespace std; 
int main(int argc, char const *argv[])
{
	/* code */
	LL sum = 0,t = 0,p,q;
	for (int a = 1; a < 10; ++a)
	{
		for (int b = 1; b < 10; ++b)
		{
			if (a==b) continue;
			for (int c = 1; c < 10; ++c)
			{
				if (a==c||b==c) continue;
				for (int d = 1; d < 10; ++d)
				{
					if (a==d||b==d||c==d) continue;
					for (int e = 1; e < 10; ++e)
					{
						if (a==e||b==e||c==e||d==e) continue;
						for (int f = 1; f < 10; ++f)
						{
							if (a==f||b==f||c==f||d==f||e==f) continue;
							for (int g = 1; g < 10; ++g)
							{
								if (a==g||b==g||c==g||d==g||e==g||f==g) continue;
								for (int h = 1; h < 10; ++h)
								{
									if (a==h||b==h||c==h||d==h||e==h||f==h||g==h) continue;
									for (int i = 1; i < 10; ++i)
									{
										if (a==i||b==i||c==i||d==i||e==i||f==i||g==i||h==i) continue;
										p = d*100+e*10+f;
										q = g*100+h*10+i;
										if (fabs(a+double(b)/c+double(p)/q-10)<0.00000001)
										{
											sum++;
												cout << a <<" " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << endl;
											if (a==0||b==0)
											{
												cout << "0000000" << a <<" " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << endl;
											}
										}
										// for (int j = 0; j < 10; ++j)
										// {
										// 	if (a==j||b==j||c==j||d==j||e==j||f==j||g==j||h==j||i==j) continue;
										// 	if (abs(a-b)==1||abs(a-d)==1||abs(a-e)==1||abs(a-f)==1) continue;
										// 	if (abs(b-e)==1||abs(b-f)==1||abs(b-g)==1||abs(b-c)==1) continue;
										// 	if (abs(c-f)==1||abs(c-g)==1) continue;
										// 	if (abs(d-e)==1||abs(d-h)==1||abs(d-i)==1) continue;
										// 	if (abs(e-h)==1||abs(e-i)==1||abs(e-j)==1||abs(e-f)==1) continue;
										// 	if (abs(f-i)==1||abs(f-j)==1||abs(f-g)==1) continue;
										// 	if (abs(g-j)==1) continue;
										// 	sum++;
										// 	// cout << a <<" " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << endl;

										// }
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}