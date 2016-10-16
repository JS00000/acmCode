#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

bool flag[26];

int main(int argc, char const *argv[])
{
	int t, kase = 0;
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		memset(flag, 0, sizeof(flag));
		char c;
		int sum = 0;
		while((c = getchar()) != '\n')
		{
			flag[c-'a'] = 1;
		}
		for (int i = 0; i < 26; ++i)
		{
			if (flag[i]) sum++;
		}
		kase++;
		printf("Case #%d: %d\n", kase, sum);
	}
	return 0;
}