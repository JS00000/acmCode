#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int n, m;
struct node
{
	int x, y, value;
}data[maxn*maxn];

bool check(int ind, int k)
{
	return ((data[ind].x >= k && data[ind].y >= (data[ind].value / k)) || (data[ind].y >= k && data[ind].x >= (data[ind].value / k)))
}


int main()
{
	int T, kase = 0;
	scanf("%d", &T);
	while(T--)
	{
		int count = 0;
		bool ret = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				char st[100];
				scanf("%s", st);
				if (st[0] != '?')
				{
					int len = strlen(st), temp = 0;
					for (int k = 0; k < len; k++) temp = temp * 10 + st[k] - '0';
					data[count].x = i+1;
					data[count].y = j+1;
					data[count++].value = temp;
				}
			}
		if (count == 0) ret = 1;
		else if (count == 1)
		{
			int mn = sqrt(data[0].value);
			for (int k = 1; k <= mn; ++k)
				if (data[0].value % k == 0 && check(0, k))
				{
					ret = 1;
					break;
				}
		}
		else if (count == 2)
		{
			int mn = sqrt(data[0].value);
			for (int k = 1; k <= mn; ++k)
				if (data[0].value % k == 0 && check(0, k))
				{
					ret = 1;
					break;
				}
		}
		else
		{

		}
		if (ret) printf("Case #%d: Yes\n", ++kase);
		else printf("Case #%d: No\n", ++kase);
	}
	return 0;
}
