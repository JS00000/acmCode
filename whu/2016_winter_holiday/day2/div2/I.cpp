#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int fa[30];

struct edge
{
	int x,y,w;
	edge(int x=0, int y=0, int w=0):x(x),y(y),w(w){}
};

edge etemp;
vector<edge> e;
int n=0,m,len,k;
char c1,c2;

int getfather(int x)
{
	if (x==fa[x])
		return x;
	else
		return fa[x]=getfather(fa[x]);
}

bool cmp(edge a, edge b)
{
	return (a.w<b.w);
}

int kruscal()
{
	int ans = 0, cnt = n;
	sort(e.begin(),e.end(),cmp);
	for (int i = 0; i < n; ++i)
	{
		fa[i] = i;
	}
	for (int i = 0; i < m; ++i)
	{
		int t1 = getfather(e[i].x);
		int t2 = getfather(e[i].y);
		if (t1!=t2)
		{
			fa[t1] = t2;
			ans+=e[i].w;
			cnt--;
			if (cnt==1) break;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	cin >> n;
	while(n!=0)
	{
		e.clear();
		m = 0;
		for (int i = 0; i < n-1; ++i)
		{
			while(!isalpha(c1=getchar()));
			cin >> k;
			for (int j = 0; j < k; ++j)
			{
				while(!isalpha(c2=getchar()));
				cin >> len;
				etemp.x = c1-'A';
				etemp.y = c2-'A';
				etemp.w = len;
				e.push_back(etemp);
				m++;
			}
		}
		cout << kruscal() << '\n';
		cin >> n;
	}
	return 0;
}
