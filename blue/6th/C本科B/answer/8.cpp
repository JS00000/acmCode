#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	int w,m,n,xm,xn,ym,yn,ans=0;
	cin >> w >> m >> n;
	ym = (m-1)/w;
	yn = (n-1)/w;
	if (ym%2!=0)
	{
		xm = w-(m-1)%w;
	}
	else
	{
		xm = (m-1)%w+1;
	}
	if (yn%2!=0)
	{
		xn = w-(n-1)%w;
	}
	else
	{
		xn = (n-1)%w+1;
	}

	if (xm-xn<0)
	{
		ans-=xm-xn;
	}
	else
	{
		ans+=xm-xn;
	}
	if (ym-yn<0)
	{
		ans-=ym-yn;
	}
	else
	{
		ans+=ym-yn;
	}

	cout << ans << "\n";
	return 0;
}
