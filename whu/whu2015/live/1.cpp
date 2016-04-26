// unfinished
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	priority_queue<string> q;
	int n,k;
	while(scanf("%d%d", &n, &k) == 2)
	{
		char num[1000001], temp[1000000];
		getchar();
		fgets(num, n + 1, stdin);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i != j)
				{
					temp[i] = num[i];
				}
			}
		}
		string st = num;
		// printf("%lu\n", st.length());
		printf("%s\n", num);
	}
	return 0;
}
