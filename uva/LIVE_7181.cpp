#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

map<int, int> group;

int main()
{
	int n, k, temp;
	while(~scanf("%d%d", &n, &k))
	{
		group.clear();
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &temp);
			group[temp]++;
		}
		for (std::map<int, int>::iterator it = group.begin(); it != group.end(); ++it)
		{
			if (it->second % k != 0)
			{
				printf("%d\n", it->first);
				break;
			}
		}
	}
	return 0;
}
