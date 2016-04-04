#include "iostream"
#include "string"

using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while(n!=0)
	{
		int j=0;
		int k=0;
		string str;
		string in[1000];
		int num[1000]={0};
		while(k<n)
		{
			cin >> str;
			bool p = false;
			for (int i = 0; i < j; ++i)
			{
				if (str==in[i])
				{
					p = true;
					num[i]++;
				}
			}
			if (!p)
			{
				in[j] = str;
				num[j]++;
				j++;
			}
			k++;
		}
		int max = 0;
		int maxx = 0;
		for (int i = 0; i < n; ++i)
		{
			if (num[i]>max)
			{
				max = num[i];
				maxx = i;
			}
		}
		cout << in[maxx] << endl;
		cin >> n;
	}
}
