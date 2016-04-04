#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k,i,j,t,b,ans;
	int f[100002];
	// cin >> n >> k;
	n = 5;
	k = 17;
	if (k<=n)
	{
		cout << n-k << '\n';
		return 0;
	}
	ans = 0;
	if (n==0)
	{
		n = 1;
		ans = 1;
	}
	t = n;
	while(t*2<k)
	{
		t*=2;
		ans++;
	}
	cout << ans << ' ' << t << '\n';
	for (int i = 0; i <= k; ++i)
	{
		f[i] = -1;
	}
	f[0] = 0;
	j = 1;
	while(j<=t)
	{
		f[j] = 1;
		j*=2;
	}
	b = k-t;

	for (int i = 3; i <= b; ++i)
	{
		if (f[i]==-1)
		{
			if (f[i-1]<f[i+1])
			{
				f[i] = f[i-1]+1;
			}
			else
			{
				f[i] = f[i+1]+1;
			}
		}
		j = i;
		while(j<=b)
		{
			f[j] = f[i];
			j*=2;
		}
	}
	if (f[b]<(1+f[t-b]))
		ans += f[b];
	else
		ans += 1+f[t-b];
	for (int i = 0; i <= b; ++i)
	{
		cout << f[i] << ' ';
	}
	cout << '\n';
	cout << ans << endl;
	return 0;
}
