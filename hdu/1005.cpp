#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
	int A,B,n;
	cin >> A >> B >> n;
	while(A||B||n)
	{
		int cirArr[50];
		int cir,cirF;
		bool p = false;
		cirArr[0] = 1;
		cirArr[1] = 1;
		int t=1;
		while(!p)
		{
			t++;
			cirArr[t] = (A*cirArr[t-1] + B*cirArr[t-2]) % 7;
			for (int i = 0; i < t-1; ++i)
			{
				if (cirArr[i]==cirArr[t-1] && cirArr[i+1]==cirArr[t])
				{
					p = true;
					cirF = i;
					cir = t-i-1;
					break;
				}
			}
		}
		cout << cirArr[((n-1-cirF)%cir)+cirF] << endl;
		cin >> A >> B >> n;
	}
	return 0;
}