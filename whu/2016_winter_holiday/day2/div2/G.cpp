#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct graph
{
	typedef vector<int> VI;
	VI info, next, to;
	graph(int n = 0, int m = 0):to(0),next(0){
		info.resize(n);
		next.reserve(m);
		to.reserve(m);
	}
	int edge_size()
	{
		return to.size();
	}
};

int main(int argc, char const *argv[])
{
	int k;
	cin >> k;
	while(k--)
	{
		cin >> n >> m;
		for (int i = 0; i < n-1; ++i)
		{
			cin >> 
		}
	}
	return 0;
}