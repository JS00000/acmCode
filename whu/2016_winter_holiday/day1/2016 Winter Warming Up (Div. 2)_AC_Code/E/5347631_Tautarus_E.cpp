#include<iostream>
using namespace std;
const int maxn=222222;
typedef long long ll;
const ll INF=1e9+9;
int a[maxn];
int main()
{
	int n;cin>>n;
	int ans=0,cnt=0,mm=INF;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mm=min(mm,a[i]);
	}
	for(int i=0;i<2*n;i++)
	{
		if(a[i%n]>mm)cnt++;
		else cnt=0;
		ans=max(ans,cnt);	
	}
	cout<<(ll)ans+(ll)n*(ll)mm<<endl;
}