#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while(n)
	{
		long sum = 0;
		int next,last = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> next;
			if (next>=last)
			{
				sum += 6*(next-last)+5;
			}
			else
			{
				sum += 4*(last-next)+5;
			}
			last = next;
		}
		cout << sum << endl;
		cin >> n;
	}
	return 0;
}