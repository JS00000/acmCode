#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool check(char str[])
{
	int len = strlen(str);
	int stack[len], ik;
	for (int p = 0; p < 2; ++p)
	for (int q = 0; q < 2; ++q)
	for (int r = 0; r < 2; ++r)
	for (int s = 0; s < 2; ++s)
	for (int t = 0; t < 2; ++t)
	{
		ik = 0;
		for (int is = len-1; is >= 0; --is)
		{
			switch(str[is])
			{
				case 'p': stack[ik++] = p;break;
				case 'q': stack[ik++] = q;break;
				case 'r': stack[ik++] = r;break;
				case 's': stack[ik++] = s;break;
				case 't': stack[ik++] = t;break;
				case 'K': stack[ik-2] = stack[ik-2]  && stack[ik-1]; ik--; break;
				case 'A': stack[ik-2] = stack[ik-2]  || stack[ik-1]; ik--; break;
				case 'N': stack[ik-1] = !stack[ik-1]; break;
				case 'C': stack[ik-2] = !stack[ik-2] || stack[ik-1]; ik--; break;
				case 'E': stack[ik-2] = !(stack[ik-2] ^ stack[ik-1]);ik--; break;
				default: break;
			}
		}
		if (!stack[0]) return 0;
	}
	return 1;
}

int main()
{
	char str[107];
	while(scanf("%s", str), !(strlen(str) == 1 && str[0] == '0')) if (check(str)) printf("tautology\n");else printf("not\n");
	return 0;
}
