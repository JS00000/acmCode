#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	long long l,r,k;
	long long ans=1;
	bool p=false;
	// cin >> l >> r >> k;
	l=237171123124584251;
	r=923523399718980912;
	k=7150;
	while(ans<l)
	{
		if (ans>1000000000000000000/k)
		{
			cout << "-1\n";
			return 0;
		}
		ans*=k;
	}
	while(ans<=r&&ans>0)
	{
		cout << ans << " ";
		p = true;
		if (ans>1000000000000000000/k)
		{
			break;
		}
		ans*=k;
	}
	if (!p)
	{
		cout << "-1\n";
	}
	else
	{
		cout << endl;
	}
	return 0;
}
