#include <cstdio>
#include <cstring>
#define maxn 101
#define maxd 20001

int SG[maxd], flag[maxd];
void GetSG(int n = maxd-1)
{
	memset(SG, 0, sizeof(SG));
	for(int i = 1; i <= n; ++i)
	{
		memset(flag, 0, sizeof(flag));
		int j;
		for (j = 1; j < i; ++j)
		{
			flag[SG[j]] = 1;
			flag[SG[j]^SG[i-j]] = 1;
		}
		j = 0;
		while(flag[++j]);
		SG[i] = j;
	}
}

int main(int argc, char const *argv[])
{
	int n, ret = 0, temp, maxx = 0;
	int a[maxn];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp);
		a[i] = temp;
		if (temp > maxx) maxx = temp;
	}
	GetSG(maxx);
	for (int i = 0; i < n; ++i) ret ^= SG[a[i]];
	if (ret == 0) printf("Bob\n");
	else printf("Alice\n");
	return 0;
}