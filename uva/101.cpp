#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

const int maxn = 30;
vector<int> pile[maxn];
int n;

void find(int a, int &p, int &h)
{
	for (p = 0; p < n; ++p)
		for (h = 0; h < pile[p].size(); ++h)
			if (pile[p][h] == a) return;
}

void clear_above(int &p, int &h)
{
	int b;
	for (int i = h+1; i < pile[p].size(); ++i)
	{
		b = pile[p][i];
		pile[b].push_back(b);
	}
	pile[p].resize(h+1);
}

void pile_onto(int &p1, int &h, int &p2)
{
	for (int i = h; i < pile[p1].size(); ++i)
	{
		pile[p2].push_back(pile[p1][i]);
	}
	pile[p1].resize(h);
}

int main(int argc, char const *argv[])
{
	string s1="", s2;
	int a,b;
	cin >> n;
	for (int i = 0; i < n; ++i) pile[i].push_back(i);
	while(1)
	{
		cin >> s1;
		if (s1=="quit") break;
		cin >> a >> s2 >> b;
		int pa, pb, ha, hb;
		find(a, pa, ha);
		find(b, pb, hb);
		if (pa==pb) continue;
		if (s2 == "onto") clear_above(pb, hb);
		if (s1 == "move") clear_above(pa, ha);
		pile_onto(pa, ha, pb);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << i << ":";
		for (int j = 0; j < pile[i].size(); ++j)
		{
			cout << " " << pile[i][j];
		}
		cout << endl;
	}
	return 0;
}