#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main(int argc, char const *argv[])
{
	int T;
	int n;
	int a[10001];
	int p[10001];
	int num[10001];
	cin >> T;
	while(T)
	{
		long ans = 0;
		int dif=0;
		cin >> n;
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(num,0,sizeof(num));
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a,a+n);
		for (int i = 0; i < n; ++i)
		{
			if (num[a[i]]==0)
			{
				dif++;
				p[dif] = a[i];
			}
			num[a[i]]++;
		}
		int k = 0,d = 1;
		k+=num[p[1]]-1;
		for (int i = 1; i < 32; ++i)
		{
			if (num[p[1]+i]!=0)
			{
				d++;
				k+=num[p[1]+i];
			}

		}
		// cout << "k:" << k << endl;
		// cout << "d:" << d << endl;
		for (int i = 1; i <= k; ++i)
		{
			ans+=i;
		}

		for (int i = d+1; i <= dif; ++i)
		{
			for (int j = p[i]-31; j < p[i]; ++j)
			{
				if (num[j])
					ans+=num[p[i]]*num[j];
			}
			int k =num[p[i]]-1;
			for (int j = 1; j <= k; ++j)
			{
				ans+=j;
			}
		}




		// int t = p[1]+32;
		// while(!num[t])
		// {
		// 	t++;
		// }
		// for (int i = 1; i <= dif; ++i)
		// {
		// 	int k = 0;
		// 	k+=num[p[i]]-1;
		// 	for (int j = 1; j < 32; ++j)
		// 	{
		// 		k+=num[p[i]+j];
		// 	}

		// }
		// sort(a,a+n);
		// for (int i = 0; i < n-1; ++i)
		// {
		// 	for (int j = i+1; j < n; ++j)
		// 	{
		// 		if (a[j]-a[i]<32)
		// 			ans++;
		// 		else 
		// 			break;
		// 	}
		// }
		cout << ans << endl;
		T--;
	}
}