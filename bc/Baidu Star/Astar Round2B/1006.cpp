#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
	int i, d, m;
};

node a[8007];
int ori[8007];
bool p[8007];
int ans[8007];

bool cmp(node a, node b)
{
	return a.d < b.d;
}

int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d", &n))
	{
		int d;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &d);
			a[i].d = d;
			a[i].i = i;
			ori[i] = d;
		}
		sort(a, a+n, cmp);
		for (int i = 0; i < n; ++i)
		{
			int ret = 1, l = i - 1, r = i + 1;
			int minp = a[i].i, maxp = a[i].i;
			bool flag = true;
			// memset(p, 0, sizeof(p));
			memset(p, 0, (n+1) * sizeof(bool));
			// printf("%d:::::::::\n", i);
			while(l >= 0 && r < n)
			{
				minp = min(a[l].i, minp);
				minp = min(a[r].i, minp);
				maxp = max(a[l].i, maxp);
				maxp = max(a[r].i, maxp);
				// printf("%d %d %d %d\n", l,r,maxp, minp);
				if (maxp - minp == r - l)
				{
					int ll = minp, rr = maxp;
					while(ll<rr)
					{
						if (!p[ll] && !p[rr] && ori[ll] < a[i].d && ori[rr] > a[i].d)
						{
							p[ll] = 1;
							p[rr] = 1;
							ret++;
							ll++;
							rr--;
						}
						else if (!p[ll] && !p[rr] && ori[ll] > a[i].d && ori[rr] < a[i].d)
						{
							p[ll] = 1;
							p[rr] = 1;
							ret++;
							ll++;
							rr--;
						}
						else if (!p[ll] && !p[ll+1] && ori[ll] < a[i].d && ori[ll+1] > a[i].d)
						{
							p[ll] = 1;
							p[ll+1] = 1;
							ret++;
							ll+=2;
						}
						else if (!p[ll] && !p[ll+1] && ori[ll] > a[i].d && ori[ll+1] < a[i].d)
						{
							p[ll] = 1;
							p[ll+1] = 1;
							ret++;
							ll+=2;
						}
						else if (!p[rr] && !p[rr-1] && ori[rr] < a[i].d && ori[rr-1] > a[i].d)
						{
							p[rr] = 1;
							p[rr-1] = 1;
							ret++;
							rr-=2;
						}
						else if (!p[rr] && !p[rr-1] && ori[rr] > a[i].d && ori[rr-1] < a[i].d)
						{
							p[rr] = 1;
							p[rr-1] = 1;
							ret++;
							rr-=2;
						}
						else break;
					}
				}
				l--;
				r++;
			}
			a[i].m = ret;
		}
		for (int i = 0; i < n; ++i)
			ans[a[i].i] = a[i].m;
		printf("%d", ans[0]);
		for (int i = 1; i < n; ++i)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}