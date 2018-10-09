#include <cstdio>
#include <cstring>

using namespace std;

int str2i(char * instr, int len)
{
	int res = 0;
	for (int i = 0; i < len; ++i)
	{
		if (instr[i] == '\n') continue;
		res = res*10 + instr[i] - '0';
	}
	return res;
}

int n;
double sum = 0;
double ans[10000];
char str[5000017];

int main()
{
	for (int i = 1; i < 8399; ++i)
	{
		sum += 1.0/i/i;
		ans[i] = sum;
	}
	while(gets(str))
	{
		int len = strlen(str);
		if (len == 0) continue;
		if (len < 8) n = str2i(str, len);
		else n = 1102920;
		if (n < 8399)
		{
			printf("%.5f\n", ans[n]);
		}
		else if (n < 9169)
		{
			printf("1.64482\n");
		}
		else if (n < 10094)
		{
			printf("1.64483\n");
		}
		else if (n < 11228)
		{
			printf("1.64484\n");
		}
		else if (n < 12648)
		{
			printf("1.64485\n");
		}
		else if (n < 14479)
		{
			printf("1.64486\n");
		}
		else if (n < 16930)
		{
			printf("1.64487\n");
		}
		else if (n < 20380)
		{
			printf("1.64488\n");
		}
		else if (n < 25597)
		{
			printf("1.64489\n");
		}
		else if (n < 34403)
		{
			printf("1.64490\n");
		}
		else if (n < 52447)
		{
			printf("1.64491\n");
		}
		else if (n < 110292)
		{
			printf("1.64492\n");
		}
		else
		{
			printf("1.64493\n");
		}
	}

	return 0;
}