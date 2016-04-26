// unfinished
#include <cstdio>
#include <cstring>

char st[1000001];
int sv[2000100];

int main(int argc, char const *argv[])
{
	int n,k;
	while(scanf("%d%d", &n ,&k) == 2)
	{
		getchar();
		fgets(st, n + 1, stdin);
		int l = n;
		int r = n + 1;
		memset(sv,0xffffffff,n*2*sizeof(int)+10);
		bool p = 1;
		sv[l--] = n-1;
		for (int i = n-2; i >=0; --i)
		{
			if (st[i] > st[i+1] || (st[i] == st[i+1] && p))
			{
				sv[l--] = i;
				p = 1;
			}
			else
			{
				p = 0;
				sv[r++] = i;
			} 
		}
		int j = k;
		if (l+j <= n)
			while(st[sv[l+j]]==st[sv[l+j-1]] && j > 1) j--;
		else while(st[sv[l+j]]==st[sv[l+j+1]] && l + j < r - 1) j++;
		printf("%d\n", sv[l+j] + 1);
	}
	return 0;
}