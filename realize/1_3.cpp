#include <iostream>

using namespace std;
#include <iostream>
#include <cstring>

#define MAXN 10001

using namespace std;

int ans[MAXN];
bool valid[MAXN];
void getPrime(int n, int &tot, int ans[])
{
	memset(valid,true,sizeof(valid));
	for (int i = 2; i <= n; ++i)
	{
		if (valid[i]) ans[++tot] = i;
		for (int j = 1; (j<=tot) && (i*ans[j]<=n) ; ++j)
		{
			valid[i*ans[j]] = false;
			if (i%ans[j]==0) break;
		}
	}
}

int main(int argc, char const *argv[])
{
	int tot = 0;
	getPrime(10000,tot,ans);
	for (int i = 1; i <= tot; ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl << tot << endl;
	cin.get();
	return 0;
}