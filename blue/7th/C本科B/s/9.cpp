#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>

#define LL long long
#define MAXN 0x0fffffff

using namespace std; 

int a[1001];
int b[1001] = {0} ;
bool p[1001] = {0};

struct DisjointSet
{
	std::vector<int> father, rank;
	DisjointSet(int n) : father(n), rank(n)
	{
		for (int i = 0; i < n; ++i)
			father[i] = i;
	}

	int find(int v)
	{
		return father[v] = father[v]==v ? v : find(father[v]);
	}

	void merge(int x, int y)
	{
		int a = find(x), b = find(y);
		if (rank[a] < rank[b])
		{
			father[a] = b;
		}
		else
		{
			father[b] = a;
			if (rank[b]==rank[a])
			{
				++rank[a];
			}
		}
	}
};

DisjointSet d(1001);


void dfs(int x)
{
	int k,l;
	if (x!=a[x])
	{
		k = d.find(x);
		l = d.find(a[x]);
		if (k!=l)
		{
			d.merge(x,a[x]);
			dfs(a[x]);	
		}
		return;
	}
	return;
}



int main(int argc, char const *argv[])
{
	int n,sum = 0,cha = 0,lu = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		dfs(i);
	}
	for (int i = 1; i <= n; ++i)
	{
		int t = d.find(i);
		p[t] = 1;
		b[t] ++;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (p[i]) sum+=b[i]-1;
	}
	// for (int i = 1; i <=n; ++i)
	// {
	// 	cout  << b[i] << " ";
	// }
	cout << sum << endl;
	return 0;
}