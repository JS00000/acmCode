#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n,g;
int main(int argc, char const *argv[])
{
	while(scanf("%d%d",&n,&g)!=EOF)
	{
		int ans = 0;
		vector<int> w;
		for (int i = 0; i < n; ++i)
		{
			int a,b;
			cin >> a >> b;
			if (a>b) 
			{
				ans+=3;
				continue;
			}
			if (a==b)
			{
				ans+=1;
			}
			w.push_back(b-a);
		}
		sort(w.begin() , w.end() );
		int i = 0;
		while(g)
		{
			if (i==w.size()) break;
			if (w[i]==0)
			{
				g--;
				ans+=2;
				i++;
				continue;
			}
			if (g>w[i])
			{
				g = g-w[i]-1;
				ans+=3;
				i++;
				continue;
			}
			if (g==w[i])
			{
				g = 0;
				ans+=1;
				i++;
				continue;
			}
			break;
		}
		cout << ans << endl;
	}
	return 0;
}