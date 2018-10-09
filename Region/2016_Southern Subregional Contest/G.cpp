#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

struct node
{
	int s, t;
}event[maxn];

bool cmp(node a, node b)
{
	return a.s <= b.s;
}

int n, s, d, ei = 1;

int main()
{
	event[0].s = 0;
	event[0].t = 0;
	event[1].s = ~0u>>1;
	event[1].t = ~0u>>1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &s, &d);
		bool flag  = true;
		for (int j = 0; j < ei; j++)
		{
			if (s > event[j].t && s+d-1 < event[j+1].s)
			{
				printf("%d %d\n", s, s+d-1);
				flag = false;
				event[++ei].s = s;
				event[ei].t = s+d-1;
				sort(event, event+ei+1, cmp);
				break;
			}
		}
		if (flag)
		{
			for (int j = 0; j < ei; j++)
			{
				if (event[j].t + d < event[j+1].s)
				{
					printf("%d %d\n", event[j].t + 1, event[j].t + d);
					event[++ei].s = event[j].t + 1;
					event[ei].t = event[j].t + d;
					sort(event, event+ei+1, cmp);
					break;
				}
			}
		}
	}
}
