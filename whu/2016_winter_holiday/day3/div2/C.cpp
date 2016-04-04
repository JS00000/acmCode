#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 1e18

using namespace std;

long f[400020];
long from[400020];
bool p[400020];
int n,k;

void path()
{
	int j=k;
	while(j!=n)
	{
		cout << j << "->";
		j = from[j];
	}
	cout << n <<'\n';
}

int main(int argc, char const *argv[])
{
	cin >> n >> k;
	// n = 100;
	// k = 10000;
	memset(p,false,sizeof(p));
	for (int i = 0; i < 400020; ++i)
		f[i] = INF;
	if (k<=n)
	{
		cout << n-k << '\n';
		return 0;
	}
	f[n] = 0;
	p[n] = true;
	if (n==0)
	{
		n = 1;
		f[1] = 1;
		p[1] = true;
	}
	for (int i = 0; i < n; ++i)
	{
		f[i] = n-i;
		from[i] = i+1;
		p[i] = true;
	}
	for (int i = n+1; i < n*2; ++i)
	{
		f[i] = i-n;
		from[i] = i-1;
		p[i] = true;
	}
	int t = n;
	while(t<k)
	{
		for (int i = 1; i < t*2; ++i)
		{
			if (p[i])
			{
				if (f[i]+1<f[i*2])
				{
					f[i*2] = f[i]+1;
					from[i*2] = i;
					p[i*2] = true;
				}
				else
				{
					p[i] = false;
				}
			}
		}
		for (int i = 1; i < t*2; ++i)
		{
			// f[i] = min(f[i],min(f[i-1],f[i+1]));
			if (f[i-1]<f[i+1])
			{
				if (f[i-1]+1<f[i])
				{
					f[i] = f[i-1]+1;
					from[i] = i-1;
					p[i] = true;
				}
			}
			else
			{
				if (f[i+1]+1<f[i])
				{
					f[i] = f[i+1]+1;
					from[i] = i+1;
					p[i] = true;
				}
			}
		}
		t*=2;
	}
	// for (int i = 0; i < k+10; ++i)
	// {
		// cout << i << ':' << f[i] << '\n';
	// }
	// for (int i = 0; i < k+10; ++i)
	// {
		// cout << from[i]<< ' ';
	// }
	// cout << '\n';
	// path();
	cout << f[k] << endl;
	return 0;
}