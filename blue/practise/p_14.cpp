#include <cstdio>
#define maxn 101

int main(int argc, char const *argv[])
{
	int n = 0, ret = 0, temp, maxx = 0;
	int a[maxn];
	int pos[maxn];
	int maxnext[maxn];
	while(~scanf("%d", pos + n)) n++;
	for (int i = 0; i < n - 1; ++i) maxnext[i] = pos[i+1] - pos[i] - 1;
	for (int i = 0; i < n/2; ++i) a[i] = pos[i*2+1] - pos[i*2] - 1;
	for (int i = 0; i < n/2; ++i) ret ^= a[i];
	if (ret == 0) printf("-1\n");
	else
	{
		for (int i = 0; i < n/2; ++i)
		{
			int na = a[i] ^ ret;
			if (na < a[i]) 
			{
				printf("%d %d\n", pos[i*2], pos[i*2+1] - na - 1);
				break;
			}
			else if (na > a[i] && maxnext[i*2+1] > na - a[i]) 
			{
				printf("%d %d\n", pos[i*2+1], pos[i*2+1] + na - a[i]);
				break;
			}
		}
	}
	return 0;
}
