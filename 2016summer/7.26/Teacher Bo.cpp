#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

pair<int, int> pos[100007];
bool dis[200010];

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m, a, b;
		scanf("%d%d", &n, &m);
		if (n*(n-1) > 4*m+2) 
		{
			for (int i = 0; i < n; ++i)
			{
				scanf("%d%d", &a, &b);
			}
			printf("YES\n");
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				scanf("%d%d", &a, &b);
				pos[i].first = a;
				pos[i].second = b;
			}
			memset(dis, 0, sizeof(dis));
			bool flag = 0;
			for (int i = 0; i < n; ++i)
			{
				if (flag) break;
				for (int j = i+1; j < n; ++j)
				{
					int d = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
					if (dis[d])
					{
						printf("YES\n");
						flag = 1;
						break;
					}
					else dis[d] = 1;
				}
			}
			if (!flag) printf("NO\n");
		}

	}
	return 0;
}