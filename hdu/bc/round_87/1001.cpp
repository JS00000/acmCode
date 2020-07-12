#include <cstdio>
#include <vector>
#include <algorithm>

#define maxn 300000

using namespace std;

int n;
int a[550];
vector<int> v;

int gcd(int a, int b)
{
	return b==0?a:gcd(b, a%b);
}


int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		v.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a+i);
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (i != j) v.push_back(gcd(a[i],a[j]));
			}
		}
		sort(v.begin(), v.end());
		vector<int>::iterator end_unique =  unique(v.begin(), v.end());
		v.erase(end_unique, v.end());
		std::vector<int>::iterator i = v.begin();
		printf("%d", *i);
		i++;
		for (; i != v.end(); ++i)
			printf(" %d", *i);
		printf("\n");
	}
	return 0;
}