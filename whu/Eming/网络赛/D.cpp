#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	int T,slen,mlen,lenrm;
	bool p;
	string str,m;
	cin >> T;
	while(T--)
	{
		cin >> str;
		slen = str.length();
		lenrm = slen/3;
		mlen = 0;
		for (int i = lenrm; i > 0; i--)
		{
			p = false;
			m = str.substr(0,i);
			if (str.substr(slen-i)==m)
			{
				for (int j = i; j <= slen-i*2; ++j)
				{
					if (str.substr(j,i)==m)
					{
						p = true;
						break;
					}
				}
				if (p) 
				{
					mlen = i;
					break;
				}
			}
		}
		if (mlen==0) 
		{
			cout << "Naive Music\n";
		}
		else
		{
			cout << str.substr(0,mlen) << endl;
		}
		// cout << "Sdafsdf" << endl;
	}
	return 0;
}