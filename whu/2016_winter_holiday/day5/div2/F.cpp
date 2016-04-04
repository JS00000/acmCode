#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long LL;
using namespace std;

int n,x1,x2,y1,y2,x,y,t=0;

struct inf
{
	int pos,start,end,deep;
};

inf edgexu[10000];
inf edgexd[10000];
inf edgeyl[10000];
inf edgeyr[10000];

bool cmp(inf a, inf b)
{
	return (a.pos<b.pos);
}

int main(int argc, char const *argv[])
{
	cin >> n;
	while(n)
	{
		LL ans = 0;
		for (int j = 0; j < n; ++j)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			x = min(x1,x2);
			x2 = max(x1,x2);
			x1 = x;
			y = min(y1,y2);
			y2 = max(y1,y2);
			y1 = y;
			x = x2 - x1;
			y = y2 - y1;
			edgexd[j].pos   = y1;
			edgexd[j].start = x1;
			edgexd[j].end   = x2;
			edgexd[j].deep  = y;
			edgexu[j].pos   = y2;
			edgexu[j].start = x1;
			edgexu[j].end   = x2;
			edgexu[j].deep  = y;
			edgeyl[j].pos   = x1;
			edgeyl[j].start = y1;
			edgeyl[j].end   = y2;
			edgeyl[j].deep  = x;
			edgeyr[j].pos   = x2;
			edgeyr[j].start = y1;
			edgeyr[j].end   = y2;
			edgeyr[j].deep  = x;
			for (int i = 0; i < min(x,y); ++i) ans+=(x-i)*(y-i);
		}
		sort(edgexu,edgexu+n,cmp);
		sort(edgexd,edgexd+n,cmp);
		sort(edgeyl,edgeyl+n,cmp);
		sort(edgeyr,edgeyr+n,cmp);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i==j) continue;
				if (edgexu[i].pos>edgexd[j].pos)
				{
					continue;
				}
				else if (edgexu[i].pos==edgexd[j].pos)
				{
					if (edgexu[i].end-2<=edgexd[j].start||edgexu[i].start>=edgexd[j].end-2)
					{
						continue;
					}
					else
					{
						int width = min(edgexu[i].end,edgexd[j].end)-max(edgexu[i].start,edgexd[j].start)-2;
						int mindeep = min(edgexu[i].deep,edgexd[j].deep);
						int maxdeep = max(edgexu[i].deep,edgexd[j].deep);
						int m = min(width,mindeep+1);
						for (int k = 1; k < m; ++k) ans+=k*(width-k);
						if (m!=width)
						{
							int m2 = min(width,mindeep+maxdeep);
							for (int k = m; k < m2; ++k)
							{
								ans+=(width-k)*mindeep;
							}
						}
					}
				}
				else 
				{
					break;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (edgeyr[i].pos>edgeyl[j].pos)
				{
					continue;
				}
				else if (edgeyr[i].pos==edgeyl[j].pos)
				{
					if (edgeyr[i].end-2<=edgeyl[j].start||edgeyr[i].start>=edgeyl[j].end-2)
					{
						continue;
					}
					else
					{
						int width = min(edgeyr[i].end,edgeyl[j].end)-max(edgeyr[i].start,edgeyl[j].start)-2;
						int mindeep = min(edgeyr[i].deep,edgeyl[j].deep);
						int maxdeep = max(edgeyr[i].deep,edgeyl[j].deep);
						int m = min(width,mindeep+1);
						for (int k = 1; k < m; ++k) ans+=k*(width-k);
						if (m!=width)
						{
							int m2 = min(width,mindeep+maxdeep);
							for (int k = m; k < m2; ++k)
							{
								ans+=(width-k)*mindeep;
							}
						}
					}
				}
				else 
				{
					break;
				}
			}
		}
		t++;
		cout << "Case " << t << ": " << ans << endl;
		cin >> n;
	}
	return 0;
}